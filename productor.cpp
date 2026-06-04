#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <queue>
#include <ctime>
#include <cstdlib>
#include"buffer.h"
#include"semaforo.h"
using namespace std;

void productor(){

    int producidos = 0;
    for(int i=0; i<tam; i++){

        Paquete p;
        p.id = i;
        p.prioridad = rand() % 2;
        p.fechaCreacion = chrono::steady_clock::now();
        p.fechaEntradaWaiting = chrono::steady_clock::now();

        waitingQueue.mtx.lock();
        waitingQueue.cola.push_back(p);
        producidos++;
        waitingQueue.mtx.unlock();

        signal(hay_datos);
    }
    cout<<"\nProducidos: "<<producidos<<endl;

}
