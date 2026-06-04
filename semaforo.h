#ifndef SEMAFORO_H_INCLUDED
#define SEMAFORO_H_INCLUDED
#include <mutex>
#include <condition_variable>

using namespace std;

extern int totalConsumidos;
extern mutex mtxConsumidos;
extern mutex mtxCout;

struct Semaforo{
    int contador;
    mutex mtx;
    condition_variable cv;
};

extern Semaforo hay_datos;
extern Semaforo hay_datos_cinta;

void init(Semaforo&s, int n);
void wait(Semaforo&s);
void signal(Semaforo&s);


#endif // SEMAFORO_H_INCLUDED
