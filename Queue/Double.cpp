#include <iostream>
#include <deque>
using namespace std;
class Deque {
private:
    deque<int> dq;
public:
    void insertFront(int value) {
        dq.push_front(value);
    }
    void insertBack(int value) {
        dq.push_back(value);
    }
    void deleteFront() {
        if (dq.empty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        dq.pop_front();
    }
    void deleteBack() {
        if (dq.empty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        dq.pop_back();
    }
    int getFront() {
        if (dq.empty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return dq.front();
    }
    int getBack() {
        if (dq.empty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return dq.back();
    }
    bool isEmpty() {
        return dq.empty();
    }
};
int main() {
    Deque dq;
    dq.insertFront(45);
    dq.insertBack(90);
    dq.insertFront(25);
    cout << "Front value: " << dq.getFront() << endl;
    cout << "Back value: " << dq.getBack() << endl;
    dq.deleteFront();
    cout << "Front value after deletion: " << dq.getFront() << endl;
    dq.deleteBack();
    cout << "Back value after deletion: " << dq.getBack() << endl;
    return 0;
}

