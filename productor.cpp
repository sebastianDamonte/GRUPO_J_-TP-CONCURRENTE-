#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <queue>
#include <ctime>
#include <cstdlib>
#include "buffer.h"
#include "semaforo.h"
#include "productor.h"

using namespace std;
int idPaquete = 0;
int producidos = 0;
mutex mtxProductoresProduciendo;
int productoresProduciendo = 1;

void productor(){
    //int producidos = 0;
   while(true){
    waitingQueue.mtx.lock();
    if(producidos >= tam){
        waitingQueue.mtx.unlock();
        break;
    }
    Paquete p;
    p.id = idPaquete;
    p.prioridad = rand() % 2;
    p.prioridadOriginal = p.prioridad;
    p.fechaCreacion = chrono::steady_clock::now();
    p.fechaEntradaWaiting = chrono::steady_clock::now();
    waitingQueue.cola.push_back(p);
    producidos++;
    idPaquete++;
    waitingQueue.mtx.unlock();

    signal(hay_datos);
    this_thread::sleep_for(chrono::milliseconds(90));
}
mtxProductoresProduciendo.lock();
productoresProduciendo--;
mtxProductoresProduciendo.unlock();
}
