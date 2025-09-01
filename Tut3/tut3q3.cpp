#include <iostream>
#include <string>
#include <stack>
using namespace std;

class ParenthesesChecker {
private:
    // Function to check if character is an opening bracket
    bool isOpeningBracket(char c) {
        return (c == '(' || c == '[' || c == '{');
    }
    
    // Function to check if character is a closing bracket
    bool isClosingBracket(char c) {
        return (c == ')' || c == ']' || c == '}');
    }
    
    // Function to check if opening and closing brackets match
    bool isMatchingPair(char opening, char closing) {
        return ((opening == '(' && closing == ')') ||
                (opening == '[' && closing == ']') ||
                (opening == '{' && closing == '}'));
    }

public:
    // Main function to check balanced parentheses
    bool isBalanced(string expression) {
        stack<char> s;
        
        for (int i = 0; i < expression.length(); i++) {
            char current = expression[i];
            
            // If current character is opening bracket, push to stack
            if (isOpeningBracket(current)) {
                s.push(current);
            }
            // If current character is closing bracket
            else if (isClosingBracket(current)) {
                // If stack is empty, no matching opening bracket
                if (s.empty()) {
                    return false;
                }
                
                // Check if top of stack matches current closing bracket
                if (isMatchingPair(s.top(), current)) {
                    s.pop();
                } else {
                    return false;
                }
            }
            // Ignore other characters (letters, numbers, spaces, etc.)
        }
        
        // Expression is balanced if stack is empty
        return s.empty();
    }
    
    // Function to provide detailed analysis
    void analyzeExpression(string expression) {
        cout << "\nAnalyzing expression: " << expression << endl;
        
        if (isBalanced(expression)) {
            cout << "✓ The expression has BALANCED parentheses!" << endl;
        } else {
            cout << "✗ The expression has UNBALANCED parentheses!" << endl;
        }
        
        // Count different types of brackets
        int round = 0, square = 0, curly = 0;
        for (char c : expression) {
            if (c == '(' || c == ')') round++;
            else if (c == '[' || c == ']') square++;
            else if (c == '{' || c == '}') curly++;
        }
        
        cout << "Bracket count - Round: " << round 
             << ", Square: " << square 
             << ", Curly: " << curly << endl;
    }
};

int main() {
    ParenthesesChecker checker;
    string expression;
    int choice;
    
    // Test cases
    string testCases[] = {
        "((()))",
        "()[]{}",
        "([{}])",
        "((())",
        "([)]",
        "{[}]",
        "",
        "((a+b)*[c-d])",
        "{[(a+b)*(c+d)]+(e*f)}",
        "((a+b)",
        "Hello World!",
        "if(condition){for(int i=0;i<n;i++){array[i]=0;}}"
    };
    
    do {
        cout << "\n===== BALANCED PARENTHESES CHECKER =====" << endl;
        cout << "1. Enter custom expression" << endl;
        cout << "2. Test predefined examples" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer
        
        switch (choice) {
            case 1:
                cout << "Enter an expression: ";
                getline(cin, expression);
                checker.analyzeExpression(expression);
                break;
                
            case 2:
                cout << "\nTesting predefined examples:" << endl;
                cout << "================================" << endl;
                
                for (int i = 0; i < sizeof(testCases)/sizeof(testCases[0]); i++) {
                    checker.analyzeExpression(testCases[i]);
                }
                break;
                
            case 3:
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);
    
    return 0;
}
