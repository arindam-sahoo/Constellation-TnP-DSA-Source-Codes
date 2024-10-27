#include <stdio.h>

void coinChange(int deno[], int n, int amt) {
    int nums[50] = {0};
    for(int i=n-1; i>=0; i--) {
        while(amt>=deno[i]) {
            amt = amt - deno[i];
            nums[i] = nums[i] + 1;
        }
    }
    printf("The Denominations are\n");
    for(int i=n-1; i>=0; i--) {
        printf("%d x %d\n", nums[i], deno[i]);
    }
}

void main() {
    int deno[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    int amt = 2898;

    int n = sizeof(deno) / sizeof(deno[0]);

    coinChange(deno, n, amt);
}