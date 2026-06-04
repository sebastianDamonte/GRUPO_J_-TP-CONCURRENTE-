#include "processingQueue.h"
#include "waitingQueue.h"

void agregarALaCinta() {
    int indice = buscarMayorPrioridad(waitingQueue); //agarramos el paquete de prioridad mas alta que entro primero
    Paquete p = waitingQueue.cola[indice]; //copia del paquete para poder agregarlo despues
    waitingQueue.cola.erase(waitingQueue.cola.begin() + indice); //lo borramos de la otra queue si ya paso a la cinta,begin + indice porque no funciona solo con indice
    processingQueue.cola.push_back(p); //lo agregamos a la cinta con la copia
}
