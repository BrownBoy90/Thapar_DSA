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

int main() {
    string input;
    
    cout << "Enter a string to reverse: ";
    getline(cin, input);
    
    cout << "\nOriginal string: " << input << endl;
    
    // Using STL stack
    string reversed1 = reverseStringSTL(input);
    cout << "Reversed string (STL): " << reversed1 << endl;
    
    
    return 0;
}
