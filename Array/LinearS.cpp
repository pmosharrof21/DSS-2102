#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}
int main() {
    int arr[] = {5, 6, 9, 10, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = linearSearch(arr, size, target);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}

