#include <bits/stdc++.h>

// Helper function to print arrays
void printArray(const std::string& title, int arr[], int size) {
    std::cout << title;
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Increasing order
/**
 * @brief Helper function to maintain the Max Heap property (sift-down).
 * @param arr The array representing the heap.
 * @param n   The size of the heap.
 * @param i   The index of the root of the subtree to heapify.
 */
void max_heapify(int arr[], int n, int i) {
    int largest = i;     // Initialize largest as root
    int left = 2 * i + 1;    // Left child index
    int right = 2 * i + 2;   // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        max_heapify(arr, n, largest);
    }
}

/**
 * @brief Performs Heapsort for increasing (ascending) order.
 * @param arr The array to sort.
 * @param n   The size of the array.
 */
void heapSort_increasing(int arr[], int n) {
    // --- 1. Build a Max Heap ---
    // Start from the last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }

    // --- 2. Extract elements one by one ---
    for (int i = n - 1; i > 0; i--) {
        // Move current root (max element) to the end
        std::swap(arr[0], arr[i]);

        // Call max_heapify on the reduced heap (size i)
        max_heapify(arr, i, 0);
    }
}

/**
 * @brief Helper function to maintain the Min Heap property (sift-down).
 */
void min_heapify(int arr[], int n, int i) {
    int smallest = i;    // Initialize smallest as root
    int left = 2 * i + 1;   // Left child index
    int right = 2 * i + 2;  // Right child index

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);

        // Recursively heapify the affected sub-tree
        min_heapify(arr, n, smallest);
    }
}

/**
 * @brief Performs Heapsort for decreasing (descending) order.
 * @param arr The array to sort.
 * @param n   The size of the array.
 */
void heapSort_decreasing(int arr[], int n) {
    // --- 1. Build a Min Heap ---
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_heapify(arr, n, i);
    }

    // --- 2. Extract elements one by one ---
    for (int i = n - 1; i > 0; i--) {
        // Move current root (min element) to the end
        std::swap(arr[0], arr[i]);

        // Call min_heapify on the reduced heap (size i)
        min_heapify(arr, i, 0);
    }
}

/*
 * ======================================================
 * MAIN FUNCTION FOR HEAPSORT
 * ======================================================
 */

int main() {
    std::cout << "--- Heapsort (Increasing) ---" << std::endl;
    int arr_inc[] = {12, 11, 13, 5, 6, 7};
    // Calculate size of the C-style array
    int n_inc = sizeof(arr_inc) / sizeof(arr_inc[0]);
    
    printArray("Original array (inc): ", arr_inc, n_inc);
    heapSort_increasing(arr_inc, n_inc);
    printArray("Sorted (increasing):  ", arr_inc, n_inc);

    std::cout << "\n--- Heapsort (Decreasing) ---" << std::endl;
    int arr_dec[] = {12, 11, 13, 5, 6, 7};
    // Calculate size of the C-style array
    int n_dec = sizeof(arr_dec) / sizeof(arr_dec[0]);
    
    printArray("Original array (dec): ", arr_dec, n_dec);
    heapSort_decreasing(arr_dec, n_dec);
    printArray("Sorted (decreasing):  ", arr_dec, n_dec);

    return 0;
}