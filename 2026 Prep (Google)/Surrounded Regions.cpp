https://leetcode.com/problems/surrounded-regions/description/

Easy - Start DFS from all the Corner Zeroes.

Whatever is not visited after this - convert them to X

class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>> &vis) {
        if (vis[i][j]) return;
        vis[i][j] = 1;

        //movements (in vertical and horizontal directions)
        if (i + 1 < board.size() && board[i+1][j] == 'O') dfs(i+1, j, board, vis);
        if (i - 1 >= 0 && board[i-1][j] == 'O') dfs(i-1, j, board, vis);
        if (j + 1 < board[0].size() && board[i][j+1] == 'O') dfs(i, j+1, board, vis);
        if (j - 1 >= 0 && board[i][j-1] == 'O') dfs(i, j-1, board, vis);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        //traverse all the corner zeroes

        //i = 0 and i = m-1 --> first row and last row
        for (int j=0; j<n; j++) {
            if (board[0][j] == 'O' && vis[0][j] == 0) {
                dfs(0, j, board, vis);
            }
            if (board[m-1][j] == 'O' && vis[m-1][j] == 0) {
                dfs(m-1, j, board, vis);
            }
        }

        //j = 0 and j = n-1 --> first column and last column
        for (int i=0; i<m; i++) {
            if (board[i][0] == 'O' && vis[i][0] == 0) {
                dfs(i, 0, board, vis);
            }
            if (board[i][n-1] == 'O' && vis[i][n-1] == 0) {
                dfs(i, n-1, board, vis);
            }
        }

        
        //convert all the non-visited ones into X
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!vis[i][j] && board[i][j] == 'O') 
                    board[i][j] = 'X';
            }
        }
        
    }
};