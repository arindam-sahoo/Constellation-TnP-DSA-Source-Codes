#include <stdio.h>

void func1(int n);
void func2(int n);

void func2(int n) {
    if (n <= 5) {
        printf("%d ", n);
        func1(n+1);
    }
}

void func1(int n) {
    if (n <= 5) {
        printf("%d ", n);
        func2(n+1);
    }
}

void main() {
    func1(1);
}