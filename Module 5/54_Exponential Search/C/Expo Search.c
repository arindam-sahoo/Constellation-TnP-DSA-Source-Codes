#include <stdio.h>

int BinarySearch(int arr[], int left, int right, int target) {
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

int ExpoSearch(int arr[], int n, int target) {
    if (arr[0] == target) {
        return 0;
    }

    int i = 1;
    while(i < n && arr[i] <= target) {
        i = i * 2;
    }

    return BinarySearch(arr, i/2, (i<n ? i : n-1), target);
}

void main() {
    int arr[] = {3, 7, 12, 24, 32, 36, 51, 67, 86, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 0;
    printf("Enter the target:");
    scanf("%d", &target);

    int r = ExpoSearch(arr, n, target);

    if (r != -1) {
        printf("The target is found in the array in index number %d.", r);
    }
    else {
        printf("The target is not found in the array.");
    }
}