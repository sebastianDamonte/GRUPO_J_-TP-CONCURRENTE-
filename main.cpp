#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <queue>
#include <condition_variable>

#include"paquete.h"
#include"buffer.h"
#include"productor.h"
#include"consumidor.h"
#include "semaforo.h"

using namespace std;

int main()
{
    srand(time(0));

    waitingQueue.capacidad = 1550;
    processingQueue.capacidad = 5;

    //considerando que la waitingQueue no tiene limites porque no lo indica en el tp, solo hago el hay datos de los dos
    //y el hay_espacio de la cinta no lo necesitamos ya que el if dentro del consumidor ya verifica si hay o no espacio
    init(hay_datos, 0);
    init(hay_datos_cinta,0);
    thread t1(productor);
    thread t2(consumidor);
    t1.join();
    t2.join();
    //hasta ahora productor y consumidor funcionan bien, mañana vemos que falta agregar
    return 0;
}
