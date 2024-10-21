#include <stdio.h>

void func1(int n);
void func2(int n);

int mc91(int n) {
    if (n > 100) {
        return (n-10);
    }
    else {
        return mc91(mc91(n+11));
    }
}

void main() {
    printf("%d", mc91(99));
}