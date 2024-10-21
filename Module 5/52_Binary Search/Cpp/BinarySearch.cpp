#include <iostream>

int BinarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    
    return -1;
}

int main() {
    int arr[10] = {24, 27, 32, 45, 51, 52, 54, 67, 78, 98};
    int target = 54;

    int index = BinarySearch(arr, 10, target);

    if (index > -1)
        std::cout << "The target value has been found at index " << index << ".\n";
    else
        std::cout << "The target value has not been found.\n";

    return 0;
}
