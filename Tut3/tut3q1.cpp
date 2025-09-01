#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];  // Fixed size
    int top;
    int maxSize;

public:
    Stack(int size = 100) {
        top = -1;
        maxSize = (size > 100) ? 100 : size;  // Limit to 100
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Full!" << endl;
        } else {
            arr[++top] = x;
            cout << x << " pushed" << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Empty!" << endl;
        } else {
            cout << arr[top--] << " popped" << endl;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == maxSize - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack Empty!" << endl;
        } else {
            cout << "Stack: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack Empty!" << endl;
        } else {
            cout << "Top: " << arr[top] << endl;
        }
    }
};

int main() {
    int size, choice, value;
    
    cout << "Enter stack size: ";
    cin >> size;
    Stack s(size);
    
    do {
        cout << "\n1. Push  2. Pop  3. isEmpty  4. isFull  5. Display  6. Peek  7. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << (s.isEmpty() ? "Empty" : "Not Empty") << endl;
                break;
            case 4:
                cout << (s.isFull() ? "Full" : "Not Full") << endl;
                break;
            case 5:
                s.display();
                break;
            case 6:
                s.peek();
                break;
            case 7:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);
    
    return 0;
}
