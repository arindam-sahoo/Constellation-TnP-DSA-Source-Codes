#include <stdio.h>

int fibonacci(int n) {
    if (n==0)
        return 0;
    else if (n==1) 
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

void main() {
    int n = 0;
    printf("Please Enter the Position Number : ");
    scanf("%d", &n);
    printf("Fibonacci Number at Position %d : %d", n, fibonacci(n));
}