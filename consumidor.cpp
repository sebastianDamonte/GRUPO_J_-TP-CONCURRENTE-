#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <queue>
#include "processingQueue.h"
#include "buffer.h"
#include "semaforo.h"
#include "productor.h"


using namespace std;


void consumidor() {
    int consumidos = 0;

    while(true) {

        // CHECK 1: antes de wait, para no bloquearse si ya terminamos
        {
            lock_guard<mutex> lg(mtxConsumidos);
            if(totalConsumidos >= producidos) break;
        }

        wait(hay_datos);

        // CHECK 2: después de wait, por si otro hilo tomó el último mientras esperábamos
        {
            lock_guard<mutex> lg(mtxConsumidos);
            if(totalConsumidos >= producidos) {
                signal(hay_datos); // devuelve el token
                break;
            }
            totalConsumidos++;
            consumidos++;
        }

        waitingQueue.mtx.lock();
        processingQueue.mtx.lock();
        int indice = buscarMayorPrioridad();
        Paquete p = waitingQueue.cola[indice];
        agregarALaCinta(indice);
        processingQueue.mtx.unlock();
        waitingQueue.mtx.unlock();

        {
            lock_guard<mutex> lg(mtxCout);
            cout << "[CINTA] Paquete #" << p.id
                 << " | prioridad original: " << p.prioridadOriginal
                 << " | prioridad actual: " << p.prioridad
                 << (p.prioridadOriginal == 0 && p.prioridad == 1 ? " | PROMOVIDO POR AGING" : "")
                 << endl;
        }

        this_thread::sleep_for(chrono::milliseconds(550));

        processingQueue.mtx.lock();
        processingQueue.cola.erase(processingQueue.cola.begin());
        processingQueue.mtx.unlock();

        {
            lock_guard<mutex> lg(mtxCout);
            cout << "[RETIRADO] Paquete #" << p.id
                 << " | consumidos hasta ahora: " << consumidos << endl;
        }

        this_thread::sleep_for(chrono::milliseconds(270));
    }

    {
        lock_guard<mutex> lg(mtxCout);
        cout << "\nConsumidos por este hilo: " << consumidos << endl;
        cout << "Todos consumidos correctamente, ningun paquete perdido" << endl;
    }
}
