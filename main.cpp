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

//    waitingQueue.capacidad = 1550;
//    processingQueue.capacidad = 5;

    //considerando que la waitingQueue no tiene limites porque no lo indica en el tp, solo hago el hay datos de los dos
    //y el hay_espacio de la cinta no lo necesitamos ya que el if dentro del consumidor ya verifica si hay o no espacio
//    init(hay_datos, 0);
//    init(hay_datos_cinta,0);
//    thread t1(productor);
//    thread t2(consumidor);
//    t1.join();
//    t2.join();
    //hasta ahora productor y consumidor funcionan bien, mañana vemos que falta agregar


//• Configuración A: 1 Productor y 2 Consumidores
//(Escenario de baja recepción / alta disponibilidad).
//
//  thread t1(productor);
//  thread t2(consumidor);
//  thread t3(consumidor);

//   t1.join();
//   t2.join();
//   t3.join();


//Configuración B: 3 Productores y 1 Consumidor (Escenario de congestión / cuello de botella).
//
//    thread t1(productor);
//    thread t2(productor);
//    thread t3(productor);
//    thread t4(consumidor);
//    t1.join();
//    t2.join();
//    t3.join();
//    t4.join();

//Configuración C: 3 Productores y 3 Consumidores (Escenario de alta concurrencia simétrica).

//
productoresProduciendo = 3;
    thread t1(productor);
    thread t2(productor);
    thread t3(productor);
    thread t4(consumidor);
    thread t5(consumidor);
    thread t6(consumidor);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();




    cout << "\n===== METRICAS FINALES =====" << endl;
cout << "Total producidos: " << producidos << endl;
cout << "Total consumidos: " << totalConsumidos << endl;
if(cantAlta > 0)
    cout << "Tiempo promedio espera ALTA prioridad: " << tiempoTotalAlta / cantAlta << "ms" << endl;
if(cantBaja > 0)
    cout << "Tiempo promedio espera BAJA prioridad: " << tiempoTotalBaja / cantBaja << "ms" << endl;

    return 0;
}
