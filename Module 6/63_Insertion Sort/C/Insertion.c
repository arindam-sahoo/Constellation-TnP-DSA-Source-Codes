#include <stdio.h>

void InsertionSort(int arr[], int size) {
    int key, j;
    for(int i=1; i<size; i++) {
        key = arr[i];
        j = i-1;

        // Shifting the elements of arr[0 till i-1], that are >key to the position ahead of their current position.
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }

        arr[j+1] = key;
    }
}

void dispArr(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main() {
    int arr[] = {37, 86, 91, 12, 32};
    int n = sizeof(arr)/ sizeof(arr[0]);
    
    printf("Array Before Insertion Sort: ");
    dispArr(arr, n);

    InsertionSort(arr, n);
    
    printf("Array After Insertion Sort: ");
    dispArr(arr, n);
}