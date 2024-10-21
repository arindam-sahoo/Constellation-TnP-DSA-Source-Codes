#include <stdio.h>

void Merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    // Copying the Data in the temporary arrays
    for(int i=0; i<n1; i++) {
        L[i] = arr[left + i];
    }
    for(int i=0; i<n2; i++) {
        R[i] = arr[mid + i + 1];
    }

    int i=0, j=0, k=left;

    // Merging the temporary arrays back into arr
    while(i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copying the remaining elements (if any)
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sorting the first and the second halves recursively
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);

        // Merging the two sorted halves
        Merge(arr, left, mid, right);
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
    
    printf("Array Before Merge Sort: ");
    dispArr(arr, n);

    MergeSort(arr, 0, n-1);
    
    printf("Array After Merge Sort: ");
    dispArr(arr, n);
}