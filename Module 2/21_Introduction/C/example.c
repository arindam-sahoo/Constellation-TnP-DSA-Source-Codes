# include <stdio.h>

void WholeNos(int n) {
    if (n<=5) {
        printf("%d ", n);
        WholeNos(n+1);
    }
}

void main() {
    WholeNos(1);
}