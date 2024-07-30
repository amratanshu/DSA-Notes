SUDOKU SOLVER and SUDOKU CHECKER both -->

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { 
        solve(board); 
    }

    bool solve(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {

                    for (int c = '1'; c <= '9'; c++) {
                        if (isSafe(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board) == true)
                                return true;
                            
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;    
                }
                
            }
        }
        return true;
    }

    bool isSafe(vector<vector<char>>& board, int row, int col, char c) {
        // check col
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c)
            return false;
        }

        // check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == c)
            return false;
        }

        // check small grid
        int setNo = row / 3;
        int rowL = setNo * 3;

        setNo = col / 3;
        int colL = setNo * 3;

        for (int i = rowL; i < rowL + 2; i++) {
            for (int j = colL; j <= colL + 2; j++) {
                if (c == board[i][j])
                return false;
            }
        }

        return true;
    }
};

The above code is for SOLVING the sudoku - correct code

The below code is for CHECKING if the current sudoku is valid ->

The issue in your 9x9 Sudoku checker code lies in the logic of the isValidSudoku function. 
This function should check if a given Sudoku board is valid, but your current implementation attempts
to solve the Sudoku puzzle instead.

Here are the main issues:

Inappropriate Recursive Call: The isValidSudoku function should not be calling itself recursively in this 
manner. The intention of isValidSudoku should be to validate the current state of the board, not to solve it.

Incorrect Loop Ranges in isSafe Function: In the isSafe function, when checking the 3x3 sub-grid, 
the loops should iterate from rowL to rowL + 3 and from colL to colL + 3, not rowL + 2 and colL + 2.

Checking Only Validity: The function isValidSudoku should simply check the validity of the board based
 on the current entries, not attempt to fill it.

Here is a corrected version of the code that checks the validity of the current Sudoku board:


class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char c) {
        // Check particular row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == c)
                return false;
        }

        // Check particular column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c)
                return false;
        }

        // Check 3x3 sub-grid
        int rowL = (row / 3) * 3;
        int colL = (col / 3) * 3;

        for (int i = rowL; i < rowL + 3; i++) {
            for (int j = colL; j < colL + 3; j++) {
                if (board[i][j] == c)
                    return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    char c = board[i][j];
                    board[i][j] = '.'; // Temporarily empty the cell to avoid self-check
                    if (!isSafe(board, i, j, c)) {
                        return false;
                    }
                    board[i][j] = c; // Restore the cell
                }
            }
        }
        return true;
    }
};
