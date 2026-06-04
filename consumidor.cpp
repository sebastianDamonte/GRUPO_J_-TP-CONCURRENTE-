#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <queue>

#include "processingQueue.h"
#include"buffer.h"
#include"semaforo.h"

using namespace std;

void consumidor() {
    int consumidos = 0;
    for(int i = 0; i < tam; i++) {

        wait(hay_datos);

        this_thread::sleep_for(chrono::milliseconds(420));

        waitingQueue.mtx.lock();
        processingQueue.mtx.lock();

        // guardamos el paquete que se va a agregar para mostrarlo
        int indice = buscarMayorPrioridad();
        Paquete p = waitingQueue.cola[indice];
        agregarALaCinta();

        processingQueue.mtx.unlock();
        waitingQueue.mtx.unlock();

        cout << "[CINTA] Paquete #" << p.id
        << " | prioridad original: " << p.prioridadOriginal
        << " | prioridad actual: " << p.prioridad
        << (p.prioridadOriginal == 0 && p.prioridad == 1 ? " | PROMOVIDO POR AGING" : "")
        << endl;

        this_thread::sleep_for(chrono::milliseconds(550));

        processingQueue.mtx.lock();
        processingQueue.cola.erase(processingQueue.cola.begin());
        processingQueue.mtx.unlock();

        consumidos++;
        cout << "[RETIRADO] Paquete #" << p.id << " | consumidos hasta ahora: " << consumidos << endl;

        this_thread::sleep_for(chrono::milliseconds(270));
    }
        cout << "\nConsumidos total: " << consumidos << endl;
        if(consumidos == tam) {
            cout << "Todos consumidos correctamente ningun paquete perdido" << endl;
        } else {
            cout << "ERROR - se perdieron paquetes" << endl;
        }
}
