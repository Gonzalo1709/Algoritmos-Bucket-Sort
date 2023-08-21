#ifndef ALGORITMOS_Y_ESTRUCTURAS_DE_DATOS_BUCKETSORT_H
#define ALGORITMOS_Y_ESTRUCTURAS_DE_DATOS_BUCKETSORT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>

using namespace std;

// Algoritmo según https://www.geeksforgeeks.org/bucket-sort-2/:
/* Create n empty buckets (Or lists) and do the following for every array element arr[i].

    Insert arr[i] into bucket[n*array[i]]
    Sort individual buckets using insertion sort.
    Concatenate all sorted buckets.
 */

void bucketSort(float arr[], int n) {
    vector<float> bucketVector[n];

    for (int i = 0; i < n; i++) {
        int bucket = n * arr[i];
        bucketVector[bucket].push_back(arr[i]);
    }

    // Se hizo el sorting concurrente para cada bucket
    std::mutex mtx;
    std::vector<std::thread> threads;
    threads.reserve(n);
    for (int i = 0; i < n; i++) {
        threads.emplace_back([&bucketVector, &mtx, i]() {
            std::lock_guard<std::mutex> lock(mtx);
            std::sort(bucketVector[i].begin(), bucketVector[i].end());
        });
    }
    for (auto &thread : threads) {
        thread.join();
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float j : bucketVector[i]) {
            arr[index++] = j;
        }
    }
}

#endif //ALGORITMOS_Y_ESTRUCTURAS_DE_DATOS_BUCKETSORT_H
