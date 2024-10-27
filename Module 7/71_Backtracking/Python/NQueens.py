N = 4

def safe(board, row, col):
    for i in range(col):
        if board[row][i] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, N), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True

def solveNQueens(board, col):
    if col >= N:
        return True

    for i in range(N):
        if safe(board, i, col):
            board[i][col] = 1
            if solveNQueens(board, col + 1):
                return True
            board[i][col] = 0  # backtrack

    return False

def printBoard(board):
    for i in range(N):
        for j in range(N):
            print("Q" if board[i][j] == 1 else ".", end=" ")
        print()

if __name__ == "__main__":
    board = [[0] * N for _ in range(N)]

    if not solveNQueens(board, 0):
        print("Solution cannot be obtained.")
    else:
        printBoard(board)
