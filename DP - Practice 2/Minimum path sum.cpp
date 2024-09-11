https://leetcode.com/problems/minimum-path-sum/

easy grid dp. ekdum no brainer.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // pick or not pick ahh question..        

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        dp[0][0] = grid[0][0];

        for(int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (i == 0 && j ==0)
                    continue;

                if (i == 0) {
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                }
                else if (j == 0) {
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                }
                else {
                    dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
                }
            }            
        }
        
        return dp[n-1][m-1];

    }
};