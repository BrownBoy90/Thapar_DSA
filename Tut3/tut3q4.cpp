#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

class InfixToPostfix {
private:
    // Function to determine precedence of operators
    int precedence(char op) {
        switch (op) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
            case '%':
                return 2;
            case '^':
                return 3;
            default:
                return 0;
        }
    }
    
    // Function to check if character is an operator
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
    }
    
    // Function to check if character is an operand
    bool isOperand(char c) {
        return isalnum(c);
    }

public:
    // Main function to convert infix to postfix
    string infixToPostfix(string infix) {
        stack<char> st;
        string postfix = "";
        
        for (int i = 0; i < infix.length(); i++) {
            char current = infix[i];
            
            // Skip whitespace
            if (current == ' ') {
                continue;
            }
            
            // If operand, add to postfix
            if (isOperand(current)) {
                postfix += current;
            }
            // If opening parenthesis, push to stack
            else if (current == '(') {
                st.push(current);
            }
            // If closing parenthesis, pop until opening parenthesis
            else if (current == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    st.pop(); // Remove '('
                }
            }
            // If operator
            else if (isOperator(current)) {
                while (!st.empty() && st.top() != '(' && 
                       precedence(st.top()) >= precedence(current)) {
                    postfix += st.top();
                    st.pop();
                }
                st.push(current);
            }
        }
        
        // Pop remaining operators from stack
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }
        
        return postfix;
    }
    
    void displayConversion(string infix) {
        cout << "Infix Expression: " << infix << endl;
        string postfix = infixToPostfix(infix);
        cout << "Postfix Expression: " << postfix << endl;
        cout << "----------------------------------------" << endl;
    }
};

int main() {
    InfixToPostfix converter;
    
    cout << "=== INFIX TO POSTFIX CONVERTER ===" << endl;
    cout << "----------------------------------------" << endl;
    
    // Test cases
    converter.displayConversion("a+b*c");
    converter.displayConversion("(a+b)*c");
    converter.displayConversion("a+b*c-d");
    converter.displayConversion("(a+b)*(c-d)");
    converter.displayConversion("a^b^c");
    converter.displayConversion("(a+b)^(c-d)");
    
    // Interactive mode
    string userInput;
    cout << "\nEnter an infix expression (or 'exit' to quit): ";
    getline(cin, userInput);
    
    while (userInput != "exit") {
        converter.displayConversion(userInput);
        cout << "Enter another infix expression (or 'exit' to quit): ";
        getline(cin, userInput);
    }
    
    return 0;
}
