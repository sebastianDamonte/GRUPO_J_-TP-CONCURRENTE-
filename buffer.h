#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED
#include"paquete.h"
#include <condition_variable>
#include <vector>
#include <mutex>

using namespace std;

const int tam = 5;
const int limit=5;

struct Buffer
{
    vector<Paquete> cola;
    mutex mtx;
    condition_variable cv;
    int capacidad;
};

extern Buffer waitingQueue;
extern Buffer processingQueue;



#endif // COLAS_H_INCLUDED
