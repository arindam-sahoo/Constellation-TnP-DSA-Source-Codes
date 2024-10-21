#include <stdio.h>

void BubbleSort(int arr[], int n) {
    int swapped = 0;

    for(int i=0; i<n-1; i++) {
        swapped = 0;
        for(int j=0; j<n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
                swapped = 1;
            }
        }
    }
}

void displayArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}

void main() {
    int arr[] = {91, 32, 86, 37, 12};
    // No. of elements = Size of Array / Size of One Element
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array\n");
    displayArray(arr, n);
    printf("\n");

    BubbleSort(arr, n);
    printf("Sorted Array\n");
    displayArray(arr, n);
}