#include <iostream>
#include <vector>
using namespace std;
void countingSort(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    vector<int> count(max + 1, 0);
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    vector<int> output(size);
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int arr[] = {5, 9, 3, 8, 3, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr, size);
    printArray(arr, size);
    return 0;
}

