#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class PriorityQueue {
private:
    priority_queue<int> pq;
public:
    void insert(int value) {
        pq.push(value);
    }
    int extractMax() {
        if (pq.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int maxValue = pq.top();
        pq.pop();
        return maxValue;
    }
    int getMax() {
        if (pq.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return pq.top();
    }
    bool isEmpty() {
        return pq.empty();
    }
};
int main() {
    PriorityQueue pq;
    pq.insert(45);
    pq.insert(78);
    pq.insert(28);
    pq.insert(96);
    cout << "Max value: " << pq.getMax() << endl;
    cout << "Extracted max value: " << pq.extractMax() << endl;
    cout << "Max value after extraction: " << pq.getMax() << endl;
    return 0;
}

