#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[100];
    int front, rear, capacity, size;
    
public:
    CircularQueue(int cap) {
        capacity = cap;
        front = 0;
        rear = -1;
        size = 0;
    }
    
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
        cout << "Enqueued: " << item << endl;
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % capacity;
        size--;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        int temp = front;
        for (int i = 0; i < size; i++) {
            cout << arr[temp] << " ";
            temp = (temp + 1) % capacity;
        }
        cout << endl;
    }
    
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }
};

void circularQueueMenu() {
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
                return;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}

int main() {
    circularQueueMenu();
    return 0;
}
