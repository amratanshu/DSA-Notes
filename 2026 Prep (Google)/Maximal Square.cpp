https://leetcode.com/problems/maximal-square/description/?envType=company&envId=google&favoriteSlug=google-three-months

use DP exactly the same as we did in Question "Count submatrices with all 1s"

dp[i][j] will represent the max size of the square with its right bottom ending at i, j

Actually Exactly the same as Count Submatrices with all 1s Question

SOLUTION ->

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        int maxi = 0;
        
        // Populate first column
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == '1') { // Changed to '1'
                dp[i][0] = 1;
                maxi = max(maxi, dp[i][0]); // Update maxi for boundary cases
            }
        }

        // Populate first row
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == '1') { // Changed to '1'
                dp[0][j] = 1;
                maxi = max(maxi, dp[0][j]); // Update maxi for boundary cases
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '1') { // Changed to '1'
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
                maxi = max(maxi, dp[i][j]);
            }
        }
        
        return maxi * maxi;
    }
};