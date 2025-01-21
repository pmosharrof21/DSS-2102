#include <iostream>
#include <stack>
using namespace std;
void swapTop(stack<int>& s) {
    if (s.size() < 2) {
        cout << "Stack does not have enough elements to swap.\n";
        return;
    }
    int top1 = s.top();
    s.pop();
    int top2 = s.top();
    s.pop();
    s.push(top1);
    s.push(top2);
}
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Original stack: ";
    printStack(s);
    s.push(10);
    s.push(20);
    s.push(30);
    swapTop(s);
    cout << "Stack after swapping top two elements: ";
    printStack(s);
    return 0;
}

