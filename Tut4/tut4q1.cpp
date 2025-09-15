#include <iostream>
using namespace std;

class SimpleQueue {
private:
    int arr[100];
    int front, rear, capacity;
    
public:
    SimpleQueue(int size) {
        capacity = size;
        front = 0;
        rear = -1;
    }
    
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        arr[++rear] = item;
        cout << "Enqueued: " << item << endl;
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
    }
    
    bool isEmpty() {
        return front > rear;
    }
    
    bool isFull() {
        return rear == capacity - 1;
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
    
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }
};

void simpleQueueMenu() {
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
                return;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}

int main() {
    simpleQueueMenu();
    return 0;
}
