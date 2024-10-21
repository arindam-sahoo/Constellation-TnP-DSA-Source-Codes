#include <stdio.h>

int LinearSearch(int arr[], int target) {
    for(int i=0; i<10; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void main() {
    int arr[10] = {27,45,32,98,78,67,54,24,51,52};
    int target = 54;

    int index = LinearSearch(arr, target);

    if (index>-1)
        printf("The target value has been found at index %d.", index);
    else
        printf("The target value has not been found.");
}