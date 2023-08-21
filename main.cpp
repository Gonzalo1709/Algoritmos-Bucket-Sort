#include <iostream>
#include <random>
#include "bucketsort.h"

using namespace std;

int main() {
    // Creando un array de floats aleatorios distribuidos uniformemente entre 0 y 1
    int arraySize = 100;
    float arr[arraySize];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < arraySize; i++) {
        arr[i] = dis(gen);
    }

    cout << "Array sin ordenar: " << endl;
    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bucketSort(arr, arraySize);

    cout << "Array ordenada: " << endl;
    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
