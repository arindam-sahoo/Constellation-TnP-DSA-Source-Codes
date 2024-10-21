#include <stdio.h>

int factorial(int n) {
    if (n==0)
        return 1;
    else
        return (n * factorial(n-1));
}

void main() {
    int n = 0;
    printf("Please Enter the Number to see its Factorial : ");
    scanf("%d", &n);
    printf("Factorial of %d : %d", n, factorial(n));
}