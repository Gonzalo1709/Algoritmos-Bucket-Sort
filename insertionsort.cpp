#include <iostream>
#include <random>
#include <iomanip> // Necesario para std::setprecision

using namespace std;

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n = 1000;
    float arr[n];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.00, 1.00);
    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }

    cout << "Array sin ordenar: " << endl;
    for (int i = 0; i < n; i++) {
        cout << std::fixed << std::setprecision(4) << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, n);

    cout << "Array ordenada: " << endl;
    for (int i = 0; i < n; i++) {
        cout << std::fixed << std::setprecision(4) << arr[i] << " ";
    }
    cout << endl;
}
