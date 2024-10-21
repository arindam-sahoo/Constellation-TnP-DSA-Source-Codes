#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n) {
    int swapped = 0;

    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap without using a temporary variable
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break; // If no elements were swapped, the array is already sorted
        }
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {91, 32, 86, 37, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted Array" << endl;
    displayArray(arr, n);

    BubbleSort(arr, n);
    cout << "Sorted Array" << endl;
    displayArray(arr, n);

    return 0;
}
