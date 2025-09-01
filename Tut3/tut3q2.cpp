#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Method 1: Using STL stack
string reverseStringSTL(string str) {
    stack<char> s;
    string result = "";
    
    // Push all characters to stack
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }
    
    // Pop all characters and build result string
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    
    return result;
}

// Method 2: Using custom stack implementation
class CharStack {
private:
    char* arr;
    int top;
    int capacity;

public:
    CharStack(int size) {
        arr = new char[size];
        capacity = size;
        top = -1;
    }
    
    ~CharStack() {
        delete[] arr;
    }
    
    void push(char c) {
        if (top < capacity - 1) {
            arr[++top] = c;
        }
    }
    
    char pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return '\0';
    }
    
    bool isEmpty() {
        return top == -1;
    }
};

string reverseStringCustom(string str) {
    CharStack stack(str.length());
    string result = "";
    
    // Push all characters to stack
    for (int i = 0; i < str.length(); i++) {
        stack.push(str[i]);
    }
    
    // Pop all characters and build result string
    while (!stack.isEmpty()) {
        result += stack.pop();
    }
    
    return result;
}

int main() {
    string input;
    
    cout << "Enter a string to reverse: ";
    getline(cin, input);
    
    cout << "\nOriginal string: " << input << endl;
    
    // Using STL stack
    string reversed1 = reverseStringSTL(input);
    cout << "Reversed string (STL): " << reversed1 << endl;
    
    // Using custom stack
    string reversed2 = reverseStringCustom(input);
    cout << "Reversed string (Custom): " << reversed2 << endl;
    
    
    return 0;
}
