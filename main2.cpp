#include "bucketsort.h"
#include <random>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

//create a .txt file to store the ordered and unordered arrays

void createFile(string fileName) {
    ofstream file;
    int arraySize = 1000000;
    float arr[arraySize];
    file.open(fileName);
    int decimalPlaces = 2;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.00, 1.00);
    for (int i = 0; i < arraySize; i++) {
        arr[i] = dis(gen);
    }

    file << "Array sin ordenar: " << endl;
    for (int i = 0; i < arraySize; i++) {
        file << (arr[i]) << " ";
    }
    cout << endl;

    bucketSort(arr, arraySize);

    file << "Array ordenada: " << endl;
    for (int i = 0; i < arraySize; i++) {
        file << (arr[i]) << " ";
    }
    cout << endl;
}

int main() {
    int arraySize = 1000000;
    float arr[arraySize];
    createFile("unorderedArray.txt");
}
