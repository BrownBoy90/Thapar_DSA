#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return -1; // Element not found
}

void testBinarySearch() {
    vector<int> arr = {11, 12, 22, 25, 34, 64, 90};
    int target = 25;
    
    int result = binarySearch(arr, target);
    if (result != -1)
        cout << "Element " << target << " found at index: " << result << endl;
    else
        cout << "Element not found" << endl;
}

int main() {
    cout << "Problem 1: Binary Search" << endl;
    testBinarySearch();
    cout << endl;
}