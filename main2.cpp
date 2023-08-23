#include "bucketsort2.h"
#include <random>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

//create a .txt file to store the ordered and unordered arrays

void createFile(string fileName) {
    ofstream file;
    int arraySize = 100000;
    double arr[arraySize];
    file.open(fileName);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.00, 1.00);
    for (int i = 0; i < arraySize; i++) {
        arr[i] = dis(gen);
    }

    file << "Array sin ordenar: " << endl;
    for (int i = 0; i < arraySize; i++) {
        file << std::fixed << std::setprecision(6) << (arr[i]) << " ";
    }
    cout << endl;

    bucket_sort(arr, arraySize); 

    file << "Array ordenada: " << endl;
    for (int i = 0; i < arraySize; i++) {
        file << (arr[i]) << " ";
    }
    cout << endl;
}

int main() {
    createFile("unorderedArray.txt");
    return 0;
}

