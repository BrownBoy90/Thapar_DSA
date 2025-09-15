#include<iostream>
using namespace std;

class SimpleQueue {
    int* arr;
    int front, rear, currSize, maxSize;
    
public:
    SimpleQueue(int size) {
        maxSize = size;
        arr = new int[maxSize];
        front = -1;
        rear = -1;
        currSize = 0;
    }
    
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (rear == -1) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = element;
        currSize++;
        cout << "Enqueued: " << element << endl;
    }
    
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int element = arr[front];
        if (currSize == 1) {
            front = -1;
            rear = -1;
        } else {
            front++;
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
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        cout << "Front element: " << arr[front] << endl;
        return arr[front];
    }
    
    ~SimpleQueue() {
        delete[] arr;
    }
};

int main() {
    SimpleQueue q(10);
    int choice, item;
    
    while (true) {
        cout << "\n=== Simple Queue Menu ===" << endl;
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
