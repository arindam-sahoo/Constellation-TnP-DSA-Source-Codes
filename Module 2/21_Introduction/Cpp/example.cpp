#include <iostream>

void WholeNos(int n) {
    if (n <= 5) {
        std::cout << n << " ";
        WholeNos(n + 1);
    }
}

int main() {
    WholeNos(1);
    return 0;
}
