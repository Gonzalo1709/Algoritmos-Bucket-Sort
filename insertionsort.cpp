#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void test(int n) {
    double* arr = new double[n];

    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        arr[i] = static_cast<double>(rand()) / RAND_MAX;
    }

    clock_t start, end;
    start = clock();
    
    insertionSort(arr, n); 

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    // cout << "Sorted Array:" << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    cout << time_taken<< endl;
    
    delete[] arr; // Don't forget to free the allocated memory
}

// int main() {
//     int arraySize = 10; // Change this to the desired array size
//     test(arraySize);

//     return 0;
// }


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