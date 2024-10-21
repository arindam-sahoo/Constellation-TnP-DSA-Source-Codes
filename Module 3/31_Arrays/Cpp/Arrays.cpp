#include <iostream>
using namespace std;

int main() {
    int x[] = {5, 4, 3, 2, 1};

    int length = sizeof(x) / sizeof(x[0]);

    cout << "Accessing elements in the array:\n";
    for (int i = 0; i < length; i++) {
        cout << *(x + i) << " ";
    }

    return 0;
}
