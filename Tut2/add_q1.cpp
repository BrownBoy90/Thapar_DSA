#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countPairsDifferenceK(vector<int> arr, int k) {
    sort(arr.begin(), arr.end());
    int count = 0;
    int left = 0, right = 1;
    int n = arr.size();
    
    while (right < n && left < n) {
        int diff = arr[right] - arr[left];
        
        if (diff == k && left < right) {
            count++;
            left++;
            right++;
        } else if (diff < k) {
            right++;
        } else {
            left++;
            if (left == right) {
                right++;
            }
        }
    }
    
    return count;
}

void testPairsDifferenceK() {
    vector<int> arr = {1, 7, 5, 9, 2, 12, 3};
    int k = 2;
    
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    cout << "Pairs with difference " << k << ": " << countPairsDifferenceK(arr, k) << endl;
}

int main() {
    cout << "Additional Problem 1: Pairs with Difference K" << endl;
    testPairsDifferenceK();
    cout << endl;
}