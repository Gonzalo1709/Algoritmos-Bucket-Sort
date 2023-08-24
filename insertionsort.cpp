#include <iostream>
#include <random>
#include <iomanip>
#include <ctime>

using namespace std;

void insertionSort(double arr[], int n) {
    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n = 1000000;
    double arr[n];
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.00, 1.00);

    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }

    cout << "Array sin ordenar:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(4) << arr[i] << " ";
    }
    cout << endl;

    clock_t start = clock();
    start = clock();

    insertionSort(arr, n);

    cout << "Array ordenada:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(4) << arr[i] << " ";
    }
    cout << endl;

    clock_t end = clock();

    cout << "Time elapsed: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}
