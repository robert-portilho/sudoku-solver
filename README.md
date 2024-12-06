# Sudoku Solver in C using Backtracking Algorithm

This program solves a Sudoku puzzle using the backtracking algorithm. It takes a 9x9 Sudoku puzzle as input, where empty cells are represented by `0`, and attempts to fill the grid with numbers from `1` to `9` following Sudoku rules. The program uses recursion and backtracking to find the correct solution.

## Input Format

The input is a 9x9 Sudoku puzzle provided in the following format. Each line contains 9 digits, where a `0` represents an empty cell that needs to be filled. Here is an example input:
800000000
003600000
070090200
050007000
000045700
000100030
001000068
008500010
090000400

The grid consists of numbers from `1` to `9` and `0` for empty cells. The program will solve this puzzle and fill in the grid with valid numbers according to Sudoku rules.

## How the Program Works

1. **Backtracking Algorithm**: The program uses the backtracking algorithm to solve the puzzle. It starts by filling empty cells with potential numbers and recursively attempts to fill the grid. If it encounters an invalid configuration, it backtracks and tries a different number.
2. **Validation**: The program uses a helper function `check()` to validate whether a number can be placed in a specific row, column, and 3x3 subgrid.
3. **Termination**: The program terminates when all cells are filled correctly or if no solution is found (though the latter is not expected for a valid input puzzle).

## Functions

The program uses the following functions to solve the Sudoku puzzle:

- **`resolve(int row, int col, int board[9][9])`**:
  - Attempts to solve the Sudoku puzzle using recursion and backtracking.
  - It recursively tries filling in each empty cell and backtracks if a conflict is encountered.

- **`check(int row, int col, int n, int board[9][9])`**:
  - Checks if a number `n` can be placed at position `(row, col)` on the Sudoku board.
  - Ensures that the number does not repeat in the same row, column, or 3x3 subgrid.

- **`printBoard(int board[9][9])`**:
  - Prints the current state of the Sudoku grid in a readable format.