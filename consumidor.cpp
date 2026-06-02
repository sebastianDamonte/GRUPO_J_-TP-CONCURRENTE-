#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <queue>

#include"buffer.h"
#include"semaforo.h"

using namespace std;


void consumidor(){
   for(int i=0; i<tam; i++){
    wait(hay_datos);

    mtx_buffer.lock();
    Paquete val =buffer.front();
    buffer.pop();
    mtx_buffer.unlock();

    signal(hay_espacio);
   }


}
