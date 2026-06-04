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
    for(int i = 0; i < tam; i++) {

        if(processingQueue.cola.size() < processingQueue.capacidad) {
            wait(hay_datos);  // espera que haya paquete en waitingQueue

            waitingQueue.mtx.lock();
            processingQueue.mtx.lock();
            agregarALaCinta(waitingQueue, processingQueue);
            processingQueue.mtx.unlock();
            waitingQueue.mtx.unlock();

            signal(hay_datos_cinta);  // avisa que hay paquete en processingQueue
        }

        wait(hay_datos_cinta);  // espera que haya paquete en processingQueue

        this_thread::sleep_for(chrono::milliseconds(550));

        processingQueue.mtx.lock();
        processingQueue.cola.erase(processingQueue.cola.begin()); //como tiene que ser un vector porque lo indicamos dentro del struct Buffer, lo borramos con erase porque no acepta pop CREO los vectores
        processingQueue.mtx.unlock();
    }
}
