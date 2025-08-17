
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// (a) Linear time approach using sum formula
int findMissingLinear(vector<int>& arr, int n) {
    int expectedSum = n * (n + 1) / 2;
    int actualSum = accumulate(arr.begin(), arr.end(), 0);
    return expectedSum - actualSum;
}

// (b) Binary search approach
int findMissingBinarySearch(vector<int>& arr, int n) {
    int low = 0, high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // If arr[mid] == mid + 1, missing number is on right side
        if (arr[mid] == mid + 1)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return low + 1;
}

void testFindMissing() {
    vector<int> arr = {1, 2, 3, 4, 6, 7, 8}; // Missing 5
    int n = 8;
    
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    cout << "Missing number (linear): " << findMissingLinear(arr, n) << endl;
    cout << "Missing number (binary): " << findMissingBinarySearch(arr, n) << endl;
}

int main() {
    cout << "Problem 3: Find Missing Number" << endl;
    testFindMissing();
    cout << endl;
}