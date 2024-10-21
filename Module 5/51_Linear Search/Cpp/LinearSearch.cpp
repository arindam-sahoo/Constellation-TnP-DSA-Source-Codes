#include <iostream>
using namespace std;

int LinearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[10] = {27, 45, 32, 98, 78, 67, 54, 24, 51, 52};
    int target = 54;

    int index = LinearSearch(arr, 10, target);

    if (index > -1)
        cout << "The target value has been found at index " << index << "." << endl;
    else
        cout << "The target value has not been found." << endl;

    return 0;
}
