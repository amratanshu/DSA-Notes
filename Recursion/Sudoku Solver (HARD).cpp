


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