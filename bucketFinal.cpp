#include <iostream>
#include <chrono>

using namespace std;

struct Bucket {
    double value;
    Bucket* next;

    Bucket() : value(0.0), next(nullptr) {}
};

// Inserta un valor en un bucket de forma ordenada
void insertBucket(Bucket*& bucket, double value) {
    Bucket* newBucket = new Bucket();
    newBucket->value = value;

    if (!bucket) {
        bucket = newBucket;
        return;
    }

    if (value < bucket->value) {
        newBucket->next = bucket;
        bucket = newBucket;
        return;
    }

    Bucket* current = bucket;
    while (current->next && value >= current->next->value) {
        current = current->next;
    }

    newBucket->next = current->next;
    current->next = newBucket;
}

void bucketSort(double arr[], int n, int numBuckets) {
    Bucket** buckets = new Bucket*[numBuckets];
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = nullptr;
    }

    // Scatter (dispersión) - Distribuir los elementos en los buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = numBuckets * arr[i];
        insertBucket(buckets[bucketIndex], arr[i]);
    }

    // Sort (ordenamiento) - Ordenar los elementos de cada bucket
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        Bucket* current = buckets[i];
        while (current) {
            arr[index++] = current->value;
            current = current->next;
        }
    }

    // Gather (recolectar) - Recolectar los elementos ordenados de los buckets
    for (int i = 0; i < numBuckets; i++) {
        Bucket* current = buckets[i];
        while (current) {
            Bucket* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] buckets;
}

int main() {
    int arraySize = 1000000;
    int numBuckets = 100000; // Número de buckets por default
    double* arr = new double[arraySize];

    srand(time(nullptr));
    for (int i = 0; i < arraySize; i++) {
        arr[i] = static_cast<double>(rand()) / RAND_MAX;
    }
    cout << "ARRAY DESORDENADO: " << endl; 
    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << " ";
    }

    cout << "----------" << endl;
    // Tomamos el tiempo de ejecución
    clock_t start, end;
    start = clock();

    bucketSort(arr, arraySize, numBuckets);
// 0.016751
//  0.007368
    cout << "Array ordenado" << endl;
    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Tiempo de ejecución: " << time_taken << " segundos" << endl;
    

    // Comprobamos que se hayan impreso los n números
    int j=0;
    for (int i = 0; i < arraySize; i++) {
        j++;
    }
    cout << j << endl;

    delete[] arr;

}