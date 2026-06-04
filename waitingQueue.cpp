#include <chrono>
#include "waitingQueue.h"
#include "buffer.h"
using namespace std;

void aplicarAging() { //con esto calculamos el tiempo que estan los paquetes de prioridad baja
    for (int i = 0; i < waitingQueue.cola.size(); i++) {

        long long msEspera = chrono::duration_cast<chrono::milliseconds>(
            chrono::steady_clock::now() - waitingQueue.cola[i].fechaEntradaWaiting
        ).count(); //todo esto da como resultado la cantidad de milisegundos que estuvo detro del waitingQueue el paquete

        if ((msEspera/1000) >= 6) { //medimos si la espera es mayor o igual a 6 segundos
            waitingQueue.cola[i].prioridad = 1; //cambio de prioridad(de baja a alta)
        }
    }
}

int buscarMayorPrioridad()
{
    aplicarAging(); //hace el "paso del tiempo" para las prioridades bajas
    int mayorPrio = 0;
    for(int i = 1;i < waitingQueue.cola.size();i++)
    {
        if(waitingQueue.cola[i].prioridad > waitingQueue.cola[mayorPrio].prioridad) //agarra la prioridad alta que entro primero
        {
            mayorPrio = i;
        }
    }

    return mayorPrio;
};
