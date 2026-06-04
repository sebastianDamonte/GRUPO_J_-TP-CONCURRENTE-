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

void productor(){
    //int producidos = 0;
    for(int i = 0; i < tam; i++){
        Paquete p;
        p.id = idPaquete;
        p.prioridad = rand() % 2;
        p.prioridadOriginal = p.prioridad;
        p.fechaCreacion = chrono::steady_clock::now();
        p.fechaEntradaWaiting = chrono::steady_clock::now();

        waitingQueue.mtx.lock();
        waitingQueue.cola.push_back(p);
        producidos++;
        idPaquete++;
        waitingQueue.mtx.unlock();

        signal(hay_datos);
    }

    // ← lock para que no se pise con los consumidores
    lock_guard<mutex> lg(mtxCout);
    cout << "\nProducidos: " << producidos << endl;
}
