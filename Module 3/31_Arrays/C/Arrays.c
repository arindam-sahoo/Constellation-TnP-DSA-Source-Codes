#include <stdio.h>

void main() {
    int x[] = {5, 4, 3, 2, 1};

    x[2] = 100;

    int length = sizeof(x) / sizeof(x[0]);
    
    printf("Accessing elements in the array:\n");
    for(int i=0; i<length; i++) {
        printf("%d ", *(x + i));
    }
}