# include <stdio.h>

void WholeNos(int n) {
    if (n<=5) {
        WholeNos(n+1);
        printf("%d ", n);
    }
}

void main() {
    WholeNos(1);
}