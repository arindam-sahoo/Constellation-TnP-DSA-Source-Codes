#include <stdio.h>
#include <stdbool.h>

#define N 4

bool safe(int board[N][N], int row, int col) {
    for(int i=0; i<col; i++)
        if (board[row][i])
            return false;

    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;

    for(int i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(int board[N][N], int col) {
    if (col>=N) {
        return true;
    }

    for(int i=0; i<N; i++) {
        if(safe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQueens(board, col+1)) {
                return true;
            }
            board[i][col] = 0; // used for removing queen (backtrack)
        }
    }

    return false; // returning false if the queen can not be placed in any row in the column
}

void printBoard(int board[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0;j<N;j++) {
            printf("%s ", board[i][j] ? "Q" : ".");
        }
        printf("\n");
    }
}

void main() {
    int board[N][N] = {0};

    if (!solveNQueens(board, 0)) {
        printf("Solution can not be obtained.");
    }
    else {
        printBoard(board);
    }
}