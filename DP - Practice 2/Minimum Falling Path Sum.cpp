https://leetcode.com/problems/minimum-falling-path-sum/

Easy grid dp - no brainer

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int dp[n][m];

        for(int j=0;j<m;j++) {
            dp[0][j] = matrix[0][j];
        }

        int mini = INT_MAX;
        for (int i=1;i<n;i++) {
            for (int j=0;j<m;j++) {
                int a=INT_MAX, b=INT_MAX, c=INT_MAX;
                if (j-1 >= 0) a = matrix[i][j] + dp[i-1][j-1];
                b = matrix[i][j] + dp[i-1][j];
                if (j+1 < m) c = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min(a, min (b,c));
            }
        }
        for (int j=0;j<m;j++) {
            mini = min (mini, dp[n-1][j]);
        }
        return mini;
    }
};