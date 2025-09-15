#include<iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int start, end, currSize, maxSize;
    
public:
    CircularQueue(int size) {
        maxSize = size;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }
    
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (end == -1) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % maxSize;
        }
        arr[end] = element;
        currSize++;
        cout << "Enqueued: " << element << endl;
    }
    
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int element = arr[start];
        if (currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % maxSize;
        }
        currSize--;
        cout << "Dequeued: " << element << endl;
        return element;
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == maxSize;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        int temp = start;
        for (int i = 0; i < currSize; i++) {
            cout << arr[temp] << " ";
            temp = (temp + 1) % maxSize;
        }
        cout << endl;
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        cout << "Front element: " << arr[start] << endl;
        return arr[start];
    }
    
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue q(10);
    int choice, item;
    
    while (true) {
        cout << "\n=== Circular Queue Menu ===" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Peek" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> item;
                q.enqueue(item);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.peek();
                break;
            case 5:
                cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
                break;
            case 6:
                cout << (q.isFull() ? "Queue is full" : "Queue is not full") << endl;
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
