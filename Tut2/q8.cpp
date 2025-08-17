#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Using hash set - O(n) time, O(n) space
int countDistinctElements(const vector<int>& arr) {
    unordered_set<int> distinctElements;
    for (int x : arr) {
        distinctElements.insert(x);
    }
    return distinctElements.size();
}

// Using sorting - O(n log n) time, O(1) extra space
int countDistinctElementsSorted(vector<int> arr) {
    if (arr.empty()) return 0;
    
    sort(arr.begin(), arr.end());
    int count = 1;
    
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i-1]) {
            count++;
        }
    }
    
    return count;
}

void testCountDistinct() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5, 5, 5};
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    cout << "Distinct elements (hash set): " << countDistinctElements(arr) << endl;
    cout << "Distinct elements (sorted): " << countDistinctElementsSorted(arr) << endl;
}

int main() {
    cout << "Problem 8: Count Distinct Elements" << endl;
    testCountDistinct();
    cout << endl;
}