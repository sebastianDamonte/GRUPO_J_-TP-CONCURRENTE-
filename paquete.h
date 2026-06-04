#ifndef PAQUETE_H_INCLUDED
#define PAQUETE_H_INCLUDED

#include <chrono>
using namespace std;

struct Paquete {
    int id;
    int prioridad;          //0 = baja, 1 = alta
    chrono::steady_clock::time_point fechaCreacion;
    chrono::steady_clock::time_point fechaEntradaWaiting;
};

#endif
