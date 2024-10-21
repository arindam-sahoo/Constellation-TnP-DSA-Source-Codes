#include <stdio.h>

int BinarySearch(int arr[], int size, int target) {
    int left = 0, right = size-1;

    while (left <= right) {
        int mid = (left + right)/2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            right = mid - 1;
        else if (arr[mid] < target)
            left = mid + 1;
    }
    
    return -1;
}

void main() {
    int arr[10] = {24,27,32,45,51,52,54,67,78,98};
    int target = 54;

    int index = BinarySearch(arr, 10, target);

    if (index>-1)
        printf("The target value has been found at index %d.", index);
    else
        printf("The target value has not been found.");
}