#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <queue>
#include"buffer.h"
using namespace std;

mutex mtx_buffer;
queue<Paquete> buffer;


