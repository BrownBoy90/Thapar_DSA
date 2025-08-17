#include <iostream>
#include <vector>
using namespace std;

// Simple O(n²) approach
int countInversions(vector<int> arr) {
    int invCount = 0;
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                invCount++;
            }
        }
    }
    
    return invCount;
}

// Optimized O(n log n) approach using merge sort
int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int invCount = 0;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }
    
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    
    return invCount;
}

int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return invCount;
}

int countInversionsOptimized(vector<int> arr) {
    vector<int> temp(arr.size());
    return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
}

void testCountInversions() {
    vector<int> arr = {2, 4, 1, 3, 5};
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    cout << "Inversions count: " << countInversions(arr) << endl;
    cout << "Inversions count (optimized): " << countInversionsOptimized(arr) << endl;
}

int main() {
    cout << "Problem 7: Count Inversions" << endl;
    testCountInversions();
    cout << endl;
}