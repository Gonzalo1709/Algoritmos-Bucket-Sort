#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



void bucketSort(vector<float>& arr) {
    int n = arr.size();
    
    // Create empty buckets
    vector<vector<float>> buckets(n);
    
    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Calculate bucket index for the element
        buckets[bucketIndex].push_back(arr[i]);
    }
    
    // Sort each bucket
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }
    
    // Concatenate the sorted buckets to get the final sorted array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float num : buckets[i]) {
            arr[index++] = num;
        }
    }
}