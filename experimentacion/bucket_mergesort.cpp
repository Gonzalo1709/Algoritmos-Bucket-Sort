#include <iostream>
#include <cmath>

using namespace std;

void merge(double arr[], int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    double leftArr[leftSize];
    double rightArr[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArr[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(double arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void bucketSort(double arr[], int size) {
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
    
    int numBuckets = size/100;
    
    

    double **buckets = new double*[numBuckets];
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = new double[size];
        for (int j = 0; j < size; j++) {
            buckets[i][j] = 0;
        }
    }

    double range = (max - min) / numBuckets;
    for (int i = 0; i < size; i++) {
        int bucketIndex = static_cast<int>((arr[i] - min) / range);
        if (bucketIndex >= numBuckets) {
            bucketIndex = numBuckets - 1;
        }
        int j = 0;
        while (buckets[bucketIndex][j] != 0) {
            j++;
        }
        buckets[bucketIndex][j] = arr[i];
    }

    for (int i = 0; i < numBuckets; i++) {
        int bucketSize = 0;
        while (buckets[i][bucketSize] != 0) {
            bucketSize++;
        }
        mergeSort(buckets[i], 0, bucketSize - 1);
    }

    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < size; j++) {
            if (buckets[i][j] == 0) {
                break;
            }
            arr[index++] = buckets[i][j];
        }
        delete[] buckets[i];
    }
    delete[] buckets;
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

    cout << "Array ordenado" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Tiempo de ejecución: " << time_taken << " segundos" << endl;
    
    int j=0;
    for (int i = 0; i < size; i++) {
        j++;
    }
    cout << j << endl;

    delete[] arr;

}


int main() {
    test(100000);
    return 0;
}
