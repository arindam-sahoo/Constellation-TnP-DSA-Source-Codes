#include <iostream>
using namespace std;

int BinarySearch(int arr[], int left, int right, int target) {
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

int ExpoSearch(int arr[], int n, int target) {
    if (arr[0] == target) {
        return 0;
    }

    int i = 1;
    while (i < n && arr[i] <= target) {
        i = i * 2;
    }

    return BinarySearch(arr, i / 2, min(i, n - 1), target);
}

int main() {
    int arr[] = {3, 7, 12, 24, 32, 36, 51, 67, 86, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the target: ";
    cin >> target;

    int result = ExpoSearch(arr, n, target);

    if (result != -1) {
        cout << "The target is found in the array at index number " << result << "." << endl;
    } else {
        cout << "The target is not found in the array." << endl;
    }

    return 0;
}
