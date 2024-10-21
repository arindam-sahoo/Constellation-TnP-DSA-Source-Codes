#include <iostream>
#include <cmath>
using namespace std;

bool JumpSearch(int arr[], int n, int target) {
    int jump = sqrt(n);
    int prev = 0;

    while (arr[min(jump, n) - 1] < target) {
        prev = jump;
        jump += sqrt(n);
        if (prev >= n) {
            return false;
        }
    }

    for (int i = prev; i < min(jump, n); i++) {
        if (arr[i] == target) {
            return true;
        }
    }

    return false;
}

int main() {
    int arr[] = {3, 7, 12, 24, 32, 36, 51, 67, 86, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 67;

    bool result = JumpSearch(arr, n, target);
    if (result) {
        cout << "The target is found in the array." << endl;
    }
    else {
        cout << "The target is not found in the array." << endl;
    }

    return 0;
}
