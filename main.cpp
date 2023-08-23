#include <iostream>
#include <random>
#include "bucketsort.h"

using namespace std;

void executiontime(){
    //Calculate execution time of a function 
    //https://stackoverflow.com/questions/2808398/easily-measure-elapsed-time
}

test_100(){
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
}

int main() {
    //Start counter
    test_100();
    //End counter
    //Print time elapsed for function
    return 0;
}
