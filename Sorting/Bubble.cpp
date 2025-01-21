#include <iostream>
using namespace std;
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int arr[] = {27, 35, 15, 18, 33, 22, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    printArray(arr, size);
    return 0;
}

