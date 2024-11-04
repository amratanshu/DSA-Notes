https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/?envType=daily-question&envId=2024-10-27

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        int sum = 0;
        for(int i=0; i<n;i++) {
            if (matrix[i][0] == 1)  {
                dp[i][0] = 1;
                sum += 1;
            }
        }

        for(int i=0; i<m;i++) {
            if (matrix[0][i] == 1)  {
                dp[0][i] = 1;
                sum += 1;
            }
        }

        if (matrix[0][0] == 1) sum = sum - 1; //it got counted twice in the above two loops

        //while populating dp table - compare with left and top and topleft. dp[i][j] is the number of matrices 
        //with the right bottom end at (i,j) ele
        for(int i=1;i<n;i++) {
            for (int j=1;j<m;j++) {
                    if (matrix[i][j] == 1) {
                        dp[i][j] = 1 + min(dp[i-1][j], min (dp[i][j-1], dp[i-1][j-1]));
                    }
                sum += dp[i][j];
            }
        }
        return sum;
    }
};