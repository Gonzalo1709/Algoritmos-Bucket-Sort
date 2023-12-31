#include <iostream>
#include <vector>

using namespace std;

void bucket_sort(double arr[], int n){

    //create a vector of floats of size n (number of buckets)
    vector<double> bucketVector[n/2];

    //initialize each bucket with an empty vector
    for(int i = 0; i < n; i++){
        int bucket = n * arr[i]; //select the corresponding bucket
        bucketVector[bucket].push_back(arr[i]); //add the element to the bucket
    }

    //sort each bucket
    for(int i = 0; i < n; i++){
        sort(bucketVector[i].begin(), bucketVector[i].end());
    }

    //concatenate each bucket
    int index = 0;
    for(int i = 0; i < n; i++){
        for(float j : bucketVector[i]){
            arr[index++] = j;
        }
    }
}