#include <iostream>
#define N 4

bool safe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(int board[N][N], int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (safe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQueens(board, col + 1))
                return true;
            board[i][col] = 0; // backtrack
        }
    }
    return false;
}

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            std::cout << (board[i][j] ? "Q " : ". ");
        std::cout << std::endl;
    }
}

int main() {
    int board[N][N] = {0};

    if (!solveNQueens(board, 0))
        std::cout << "Solution cannot be obtained." << std::endl;
    else
        printBoard(board);

    return 0;
}
