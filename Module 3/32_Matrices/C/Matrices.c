#include <stdio.h>

void main() {
    // Declaring a matrix of 3 rows and 4 columns
    int x[3][4] = {
        {4, 3, 2, 1},
        {8, 7, 6, 5},
        {12, 11, 10, 9}
    };

    x[2][2] = 100;

    printf("Accessing elements in the matrix:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++) {
            // Accessed the element at ith row and jth column
            printf("%d\t", x[i][j]);
        }
        printf("\n");
    }
}