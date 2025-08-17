#include <iostream>
#include <vector>
using namespace std;

void duplicateZeros(vector<int>& arr) {
    int n = arr.size();
    int zeros = 0;
    
    // Count zeros
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) zeros++;
    }
    
    // Work backwards to avoid overwriting
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) {
            // Place duplicate zero
            if (i + zeros < n) {
                arr[i + zeros] = 0;
            }
            zeros--;
            if (i + zeros < n) {
                arr[i + zeros] = 0;
            }
        } else {
            if (i + zeros < n) {
                arr[i + zeros] = arr[i];
            }
        }
    }
}

void testDuplicateZeros() {
    vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
    
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    duplicateZeros(arr);
    
    cout << "After duplicating zeros: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    cout << "Additional Problem 5: Duplicate Zeros" << endl;
    testDuplicateZeros();
    cout << endl;
}