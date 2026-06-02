#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED
#include"paquete.h"
const int tam=1550;
const int limit=5;

using namespace std;

extern mutex mtx_buffer;
extern queue<Paquete> buffer;

#endif // COLAS_H_INCLUDED
