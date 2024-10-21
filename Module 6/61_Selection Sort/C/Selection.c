#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[], int n) {
    int min;

    for(int i=0; i<n; i++) {
        min = i;

        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
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

    SelectionSort(arr, n);
    printf("Sorted Array\n");
    displayArray(arr, n);
}