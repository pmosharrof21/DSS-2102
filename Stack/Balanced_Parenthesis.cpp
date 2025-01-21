#include <iostream>
#include <stack>
using namespace std;
bool isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return true;
    else if (character1 == '{' && character2 == '}')
        return true;
    else if (character1 == '[' && character2 == ']')
        return true;
    else
        return false;
}
bool areParenthesesBalanced(string expr) {
    stack<char> s;
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
            s.push(expr[i]);
        if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (s.empty())
                return false;
            else if (!isMatchingPair(s.top(), expr[i]))
                return false;
            else
                s.pop();
        }
    }
    return s.empty();
}
int main() {
    string expr = "{()}[]";
    if (areParenthesesBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}

