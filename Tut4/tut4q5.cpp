#include <iostream>
using namespace std;

class StackUsingTwoQueues {
private:
    queue<int> q1, q2;
    
public:
    // Push operation - O(n) time complexity
    void push(int x) {
        // Add new element to q2
        q2.push(x);
        
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap q1 and q2
        swap(q1, q2);
    }
    
    // Pop operation - O(1) time complexity
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        
        int top = q1.front();
        q1.pop();
        return top;
    }
    
    // Peek operation - O(1) time complexity
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.front();
    }
    
    // Check if stack is empty
    bool isEmpty() {
        return q1.empty();
    }
    
    // Get size of stack
    int size() {
        return q1.size();
    }
};

int main() {
    StackUsingTwoQueues stack;
    
    cout << "Stack using Two Queues Demo:" << endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    cout << "Top element: " << stack.top() << endl;
    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;
    cout << "Top element: " << stack.top() << endl;
    
    return 0;
}
