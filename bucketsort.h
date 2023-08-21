#ifndef ALGORITMOS_Y_ESTRUCTURAS_DE_DATOS_BUCKETSORT_H
#define ALGORITMOS_Y_ESTRUCTURAS_DE_DATOS_BUCKETSORT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>

using namespace std;

void bucketSort(float arr[], int n) {
    vector<float> bucketVector[n]; //creamos un vector de floats de tamaño n (cantidad de buckets)

    for (int i = 0; i < n; i++) { //inicializamos cada bucket con un vector vacío
        int bucket = n * arr[i]; //seleccionamos el bucket correspondiente
        bucketVector[bucket].push_back(arr[i]); //agregamos el elemento al bucket
    }

    // Se hizo el sorting concurrente para cada bucket
    std::mutex mtx; 
    std::vector<std::thread> threads; //creamos un vector de hilos para cada bucket
    threads.reserve(n); //reservamos espacio para n hilos
    for (int i = 0; i < n; i++) { //inicializamos cada hilo
        threads.emplace_back([&bucketVector, &mtx, i]() { //cada hilo ordena su bucket
            std::lock_guard<std::mutex> lock(mtx); //se bloquea el mutex para que no se acceda a la misma variable
            std::sort(bucketVector[i].begin(), bucketVector[i].end()); //se ordena el bucket
        }); 
    }
    for (auto &thread : threads) { //se ejecuta cada hilo
        thread.join();
    }

    int index = 0; //índice para recorrer el arreglo
    for (int i = 0; i < n; i++) { //recorremos cada bucket
        for (float j : bucketVector[i]) { //recorremos cada elemento del bucket
            arr[index++] = j; //agregamos el elemento al arreglo
        }
    } //al finalizar, el arreglo está ordenado
}

#endif //ALGORITMOS_Y_ESTRUCTURAS_DE_DATOS_BUCKETSORT_H
