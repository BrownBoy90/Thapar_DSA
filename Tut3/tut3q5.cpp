#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

class PostfixEvaluator {
private:
    // Function to check if character is an operator
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
    }
    
    // Function to perform arithmetic operations
    double performOperation(double operand1, double operand2, char op) {
        switch (op) {
            case '+':
                return operand1 + operand2;
            case '-':
                return operand1 - operand2;
            case '*':
                return operand1 * operand2;
            case '/':
                if (operand2 == 0) {
                    throw runtime_error("Division by zero!");
                }
                return operand1 / operand2;
            case '%':
                if (operand2 == 0) {
                    throw runtime_error("Modulo by zero!");
                }
                return fmod(operand1, operand2);
            case '^':
                return pow(operand1, operand2);
            default:
                throw runtime_error("Invalid operator!");
        }
    }

public:
    // Main function to evaluate postfix expression
    double evaluatePostfix(string postfix) {
        stack<double> st;
        
        for (int i = 0; i < postfix.length(); i++) {
            char current = postfix[i];
            
            // Skip whitespace
            if (current == ' ') {
                continue;
            }
            
            // If operand (digit), push to stack
            if (isdigit(current)) {
                st.push(current - '0'); // Convert char to int
            }
            // If operator, pop two operands and perform operation
            else if (isOperator(current)) {
                if (st.size() < 2) {
                    throw runtime_error("Invalid postfix expression!");
                }
                
                double operand2 = st.top(); st.pop();
                double operand1 = st.top(); st.pop();
                
                double result = performOperation(operand1, operand2, current);
                st.push(result);
            }
            else {
                throw runtime_error("Invalid character in expression!");
            }
        }
        
        if (st.size() != 1) {
            throw runtime_error("Invalid postfix expression!");
        }
        
        return st.top();
    }
    
    void displayEvaluation(string postfix) {
        cout << "Postfix Expression: " << postfix << endl;
        try {
            double result = evaluatePostfix(postfix);
            cout << "Result: " << result << endl;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
        cout << "----------------------------------------" << endl;
    }
};

int main() {
    PostfixEvaluator evaluator;
    
    cout << "=== POSTFIX EXPRESSION EVALUATOR ===" << endl;
    cout << "Note: Use single digits (0-9) as operands" << endl;
    cout << "Supported operators: +, -, *, /, %, ^" << endl;
    cout << "----------------------------------------" << endl;
    
    // Test cases
    evaluator.displayEvaluation("23+");       // (2+3) = 5
    evaluator.displayEvaluation("23*4+");     // (2*3)+4 = 10
    evaluator.displayEvaluation("234*+");     // 2+(3*4) = 14
    evaluator.displayEvaluation("23+4*");     // (2+3)*4 = 20
    evaluator.displayEvaluation("52-3*");     // (5-2)*3 = 9
    evaluator.displayEvaluation("23^");       // 2^3 = 8
    evaluator.displayEvaluation("84/");       // 8/4 = 2
    
    // Interactive mode
    string userInput;
    cout << "\nEnter a postfix expression (or 'exit' to quit): ";
    getline(cin, userInput);
    
    while (userInput != "exit") {
        evaluator.displayEvaluation(userInput);
        cout << "Enter another postfix expression (or 'exit' to quit): ";
        getline(cin, userInput);
    }
    
    return 0;
}
