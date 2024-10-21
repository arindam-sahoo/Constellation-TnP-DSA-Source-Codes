#include <iostream>

void func1(int n);
void func2(int n);

void func2(int n) {
    if (n <= 5) {
        std::cout << n << " ";
        func1(n + 1);
    }
}

void func1(int n) {
    if (n <= 5) {
        std::cout << n << " ";
        func2(n + 1);
    }
}

int main() {
    func1(1);
    return 0;
}
