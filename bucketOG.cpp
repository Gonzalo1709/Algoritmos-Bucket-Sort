#include <iostream>
#include <cmath>

using namespace std;

void bucketSort(double arr[], int size) {
    if (size <= 0)
        return;

    // Encontramos el mínimo y el máximo del array
    double min = arr[0];
    double max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Creamos los buckets como arrays de arreglos dinámicos
    int numBuckets = size;  // Puedes ajustar esto según tus necesidades
    double **buckets = new double*[numBuckets];
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = new double[size];
        for (int j = 0; j < size; j++) {
            buckets[i][j] = 0; // Inicializamos los arreglos a 0
        }
    }

    // Distribuimos los elementos a los buckets
    double range = (max - min) / numBuckets;
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
            double key = buckets[i][j];
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

int main() {
    double arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int size = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, size);
    cout << "Sorted array is:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
