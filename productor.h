#ifndef PRODUCTOR_H_INCLUDED
#define PRODUCTOR_H_INCLUDED

extern int producidos;
extern int paquetesPendientes;
extern mutex mtxPendientes;
extern mutex mtxProductoresProduciendo;
extern int productoresProduciendo;

void productor();

#endif // PRODUCTOR_H_INCLUDED
