#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <queue>

#include"buffer.h"
#include"semaforo.h"
using namespace std;

Semaforo hay_datos;
Semaforo hay_espacio;

void productor(){
    int producidos=0;
    for(int i=0; i<tam; i++){
            //esto espera lugar
        wait(hay_espacio);
        //crea el paquete, dsp hay q agregarle la tercer variable
        Paquete p = {i, (rand()%2)};
        //tomamos la cola
        mtx_buffer.lock();
        buffer.push(p);
        producidos++;
        mtx_buffer.unlock();
        //avisamos que hay dato disponible
        signal(hay_datos);

    }
    cout<<"\nProducidos: "<<producidos<<endl;

}
