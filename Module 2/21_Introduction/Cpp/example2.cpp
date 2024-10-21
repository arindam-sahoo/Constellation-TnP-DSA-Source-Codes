#include <iostream>

void WholeNos(int n) {
    if (n <= 5) {
        WholeNos(n + 1);
        std::cout << n << " ";
    }
}

int main() {
    WholeNos(1);
    return 0;
}
