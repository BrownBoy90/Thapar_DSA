#include <bits/stdc++.h>

// Note: iostream, string, stdexcept, algorithm are included via <bits/stdc++.h>

class MinPriorityQueue {
private:
    int* heap;      // Pointer to the array
    int maxSize;    // Maximum capacity of the queue
    int currentSize; // Current number of elements in the queue

    // --- Helper functions for index arithmetic ---
    int _parent(int i) { return (i - 1) / 2; }
    int _leftChild(int i) { return 2 * i + 1; }
    int _rightChild(int i) { return 2 * i + 2; }

    /**
     * @brief Moves a node UP the heap (sift-up).
     */
    void _sift_up(int i) {
        // While the node is not the root and is smaller than its parent
        while (i > 0 && heap[i] < heap[_parent(i)]) {
            // Swap with parent
            std::swap(heap[i], heap[_parent(i)]);
            // Move up to parent's index
            i = _parent(i);
        }
    }

    /**
     * @brief Moves a node DOWN the heap (sift-down).
     */
    void _sift_down(int i) {
        int smallest = i;
        
        while (true) {
            int left = _leftChild(i);
            int right = _rightChild(i);
            smallest = i;

            // Find smallest of node and its children
            if (left < currentSize && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < currentSize && heap[right] < heap[smallest]) {
                smallest = right;
            }

            // If the smallest is the current node, we're done
            if (smallest == i) {
                break;
            }

            // Swap and continue sifting down
            std::swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    /**
     * @brief Constructor: Allocates memory for the heap.
     * @param size The maximum capacity of the priority queue.
     */
    MinPriorityQueue(int size) {
        maxSize = size;
        currentSize = 0;
        heap = new int[maxSize];
    }

    /**
     * @brief Destructor: Frees the allocated memory.
     */
    ~MinPriorityQueue() {
        delete[] heap;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    /**
     * @brief Returns the smallest item without removing it.
     */
    int peek() {
        if (isEmpty()) {
            // Using std::out_of_range requires <stdexcept>
            throw std::out_of_range("Priority queue is empty");
        }
        return heap[0];
    }

    /**
     * @brief Adds a new item to the priority queue.
     */
    void push(int item) {
        if (currentSize == maxSize) {
            throw std::out_of_range("Priority queue is full");
        }
        
        // Add item to the end
        heap[currentSize] = item;
        currentSize++;
        
        // Sift it up to its correct position
        _sift_up(currentSize - 1);
    }

    /**
     * @brief Removes and returns the smallest item.
     */
    int pop() {
        if (isEmpty()) {
            throw std::out_of_range("Priority queue is empty");
        }

        // Smallest item is at the root
        int itemToRemove = heap[0];

        // Move the LAST item to the root
        heap[0] = heap[currentSize - 1];
        currentSize--;

        // Sift the new root down
        _sift_down(0);

        return itemToRemove;
    }

    void printHeap() {
        std::cout << "Current PQ (heap): ";
        for (int i = 0; i < currentSize; ++i) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
};

/*
 * ======================================================
 * MAIN FUNCTION FOR PRIORITY QUEUE
 * ======================================================
 */

int main() {
    std::cout << "--- Priority Queue Example ---" << std::endl;
    
    // Create a PQ with a max capacity of 10
    MinPriorityQueue pq(10);

    // We use a try-catch block because push() and pop() can throw exceptions
    try {
        pq.push(10);
        pq.push(5);
        pq.push(20);
        pq.push(3); // This should become the new root

        // 
        pq.printHeap(); 
        std::cout << "Smallest item (peek): " << pq.peek() << std::endl; // Should be 3

        std::cout << "Popped: " << pq.pop() << std::endl; // Should be 3
        pq.printHeap();
        
        std::cout << "Popped: " << pq.pop() << std::endl; // Should be 5
        pq.printHeap();

        std::cout << "Popped: " << pq.pop() << std::endl; // Should be 10
        pq.printHeap();

        pq.push(7);
        pq.printHeap();
        
        std::cout << "Popped: " << pq.pop() << std::endl; // Should be 7
        std::cout << "Popped: " << pq.pop() << std::endl; // Should be 20

        std::cout << "Is queue empty? " << (pq.isEmpty() ? "Yes" : "No") << std::endl;
        
        // This line would throw an error if uncommented:
        // std::cout << "Popped: " << pq.pop() << std::endl; 

    } catch (const std::out_of_range& e) {
        // std::cerr is used for errors
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}