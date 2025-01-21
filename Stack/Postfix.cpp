#include <iostream>
#include <stack>
#include <string>
using namespace std;
int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    case '*': return operand1 * operand2;
    case '/': return operand1 / operand2;
    default: cout << "Unexpected Error \n"; return -1;
    }
}
int evaluatePostfix(string expression) {
    stack<int> s;
    for (int i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            s.push(expression[i] - '0');
        }
        else {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            int result = performOperation(expression[i], operand1, operand2);
            s.push(result);
        }
    }
    return s.top();
}
int main() {
    string expression = "378*+5-";
    cout << "Postfix Expression: " << expression << endl;
    cout << "Result: " << evaluatePostfix(expression) << endl;
    return 0;
}

