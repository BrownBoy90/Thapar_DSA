#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // If no swapping occurred, array is sorted
        if (!swapped)
            break;
    }
}

void testBubbleSort() {
    vector<int> elements = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original array: ";
    for (int x : elements) cout << x << " ";
    cout << endl;
    
    bubbleSort(elements);
    
    cout << "Sorted array: ";
    for (int x : elements) cout << x << " ";
    cout << endl;
}

int main() {
    cout << "Problem 2: Bubble Sort" << endl;
    testBubbleSort();
    cout << endl;
}