#include <stdio.h>
#include <math.h>

int JumpSearch(int arr[], int n, int target) {
    int jump = sqrt(n);

    int prev = 0;
    while (arr[jump] < target && jump < n) {
        prev = jump;
        jump += sqrt(n);
        if (jump >= n) {
            jump = n;
        }
    }

    for(int i=prev; i < jump; i++) {
        if (arr[i] == target) {
            return 1;
        }
    }

    return 0;
}

void main() {
    int arr[] = {3, 7, 12, 24, 32, 36, 51, 67, 86, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 67;

    int r = JumpSearch(arr, n, target);

    if (r == 1) {
        printf("The target is found in the array.");
    }
    else {
        printf("The target is not found in the array.");
    }
}