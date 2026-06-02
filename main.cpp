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

using namespace std;






int main()
{
    thread t1(productor);
    thread t2(consumidor);
    t1.join();
    t2.join();
    //hasta ahora productor y consumidor funcionan bien, mañana vemos que falta agregar
    return 0;
}
