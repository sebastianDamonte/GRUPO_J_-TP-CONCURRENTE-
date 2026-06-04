#ifndef SEMAFORO_H_INCLUDED
#define SEMAFORO_H_INCLUDED
#include <mutex>
#include <condition_variable>

struct Semaforo{
    int contador;
    std::mutex mtx;
    std::condition_variable cv;
};
extern Semaforo hay_espacio;
extern Semaforo hay_datos;
extern Semaforo hay_datos_cinta;
extern Semaforo hay_espacio_cinta;
void init(Semaforo&s, int n);
void wait(Semaforo&s);
void signal(Semaforo&s);


#endif // SEMAFORO_H_INCLUDED
