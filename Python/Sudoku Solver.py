from typing import List

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        n, N = 3, 9
        rows = [[0] * (N + 1) for _ in range(N)]
        cols = [[0] * (N + 1) for _ in range(N)]
        boxes = [[0] * (N + 1) for _ in range(N)]
        sudokuSolved = False

        def couldPlace(d, row, col):
            idx = (row // n) * n + col // n
            return rows[row][d] + cols[col][d] + boxes[idx][d] == 0

        def placeNumber(d, row, col):
            idx = (row // n) * n + col // n
            rows[row][d] += 1
            cols[col][d] += 1
            boxes[idx][d] += 1
            board[row][col] = str(d)

        def removeNumber(d, row, col):
            idx = (row // n) * n + col // n
            rows[row][d] -= 1
            cols[col][d] -= 1
            boxes[idx][d] -= 1
            board[row][col] = '.'

        def placeNextNumbers(row, col):
            nonlocal sudokuSolved
            if row == N - 1 and col == N - 1:
                sudokuSolved = True
            elif col == N - 1:
                backtrack(row + 1, 0)
            else:
                backtrack(row, col + 1)

        def backtrack(row, col):
            nonlocal sudokuSolved
            if board[row][col] == '.':
                for d in range(1, 10):
                    if couldPlace(d, row, col):
                        placeNumber(d, row, col)
                        placeNextNumbers(row, col)
                        if not sudokuSolved:
                            removeNumber(d, row, col)
            else:
                placeNextNumbers(row, col)

        for i in range(N):
            for j in range(N):
                if board[i][j] != '.':
                    placeNumber(int(board[i][j]), i, j)
        backtrack(0, 0)

# Main block to test the Sudoku solver
if __name__ == "__main__":
    board = [
        ["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]

    print("Original Sudoku Board:")
    for row in board:
        print(row)

    sol = Solution()
    sol.solveSudoku(board)

    print("\nSolved Sudoku Board:")
    for row in board:
        print(row)
