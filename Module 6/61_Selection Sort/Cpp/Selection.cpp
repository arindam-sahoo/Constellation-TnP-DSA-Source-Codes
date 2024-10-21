#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort(int arr[], int n) {
    int min;

    for(int i = 0; i < n; i++) {
        min = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

void displayArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {91, 32, 86, 37, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted Array" << endl;
    displayArray(arr, n);
    cout << endl;

    SelectionSort(arr, n);
    cout << "Sorted Array" << endl;
    displayArray(arr, n);
    cout << endl;

    return 0;
}
