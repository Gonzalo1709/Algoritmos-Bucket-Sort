#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

template <typename T>
void bucketSort(T arr[],int size) {
    // Encontramos el mínimo y el máximo del array
    T min = arr[0];
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Creamos los buckets como arrays de arreglos dinámicos
    int numBuckets = sqrt(size);  // cant buckets = Raiz cuadrada del size
    T **buckets = new T*[numBuckets];
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = new T[size];
        for (int j = 0; j < size; j++) {
            buckets[i][j] = 0; // Inicializamos los arreglos a 0
        }
    }
    // Distribuimos los elementos a los buckets
    T range = (max - min) / numBuckets;
    for (int i = 0; i < size; i++) {
        int bucketIndex = static_cast<int>((arr[i] - min) / range);
        // Aseguramos que el índice del bucket esté en el rango válido
        if (bucketIndex >= numBuckets) {
            bucketIndex = numBuckets - 1;
        }
        int j = 0;
        while (buckets[bucketIndex][j] != 0) {
            j++;
        }
        buckets[bucketIndex][j] = arr[i];
    }
    // Ordenamos los elementos de cada bucket usando Insertion Sort
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 1; j < size; j++) {
            if (buckets[i][j] == 0) {
                break;
            }
            T key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Concatenamos los elementos ordenados de cada bucket en el array original
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < size; j++) {
            if (buckets[i][j] == 0) {
                break;
            }
            arr[index++] = buckets[i][j];
        }
        delete[] buckets[i]; // Liberamos la memoria de cada bucket
    }
    delete[] buckets; // Liberamos el array de buckets
}

void test(int size){
    double* arr = new double[size];

    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        arr[i] = static_cast<double>(rand()) / RAND_MAX;
    }

    // Tomamos el tiempo de ejecución
    clock_t start, end;
    start = clock();
    
    bucketSort(arr,size); 

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << time_taken << endl;
    
    // int j=0;
    // for (int i = 0; i < size; i++) {
    //     j++;
    // }
    // cout << j << endl;

    delete[] arr;

}


int main() {
    cout << "10" << endl;
    test(10);
    test(10);
    test(10);
    test(10);
    test(10);

    cout<<endl;

    cout << "100" << endl;
    test(100);
    test(100);
    test(100);
    test(100);
    test(100);

    cout<<endl;

    cout << "1000" << endl;
    test(1000);
    test(1000);
    test(1000);
    test(1000);
    test(1000);

    cout<<endl;


    cout << "10000" << endl;
    test(10000);
    test(10000);
    test(10000);
    test(10000);
    test(10000);

    cout<<endl;

    cout << "100000" << endl;
    test(100000);
    test(100000);
    test(100000);
    test(100000);
    test(100000);

    cout<<endl;

    cout << "1000000" << endl;
    test(1000000);
    test(1000000);
    test(1000000);
    test(1000000);
    test(1000000);

    cout<<endl;
}

