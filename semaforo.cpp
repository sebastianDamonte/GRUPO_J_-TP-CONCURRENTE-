#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <queue>

#include "semaforo.h"

using namespace std;

int totalConsumidos = 0;
mutex mtxConsumidos;
mutex mtxCout;
long long tiempoTotalAlta = 0;
long long tiempoTotalBaja = 0;
int cantAlta = 0;
int cantBaja = 0;
mutex mtxMetricas;

Semaforo hay_datos;
Semaforo hay_datos_cinta;

void init(Semaforo&s, int n){
    s.contador = n;

};

void wait(Semaforo&s){
    unique_lock<mutex>
    lock(s.mtx);

    while(s.contador==0){
        s.cv.wait(lock);
    }
    s.contador--;

};

void signal(Semaforo&s){
    unique_lock<mutex> lock(s.mtx);

    s.contador++;

    s.cv.notify_one();
}
