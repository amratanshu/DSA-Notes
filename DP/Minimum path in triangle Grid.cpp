https://leetcode.com/problems/triangle/


Simple memoization :
This solution is not space optimized at all. Can do that!

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        if (n == 1)
            return triangle[0][0];

        vector<vector<int>> dp(n);
        
        dp[0].push_back(triangle[0][0]);

        int minForTheRow;
        for (int i=1; i<n; i++) {
            minForTheRow = INT_MAX;
            for (int j=0; j<triangle[i].size(); j++) {
                int ans;
                if (j==0) {
                    ans = triangle[i][j] + dp[i-1][j];
                }
                else if (j==triangle[i].size() - 1) {
                    ans = triangle[i][j] + dp[i-1][j-1];
                    }
                else {
                    ans = triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                }
                dp[i].push_back(ans);        
                if (ans<minForTheRow)
                    minForTheRow = ans;
            }
        }

        return minForTheRow;

    
    }
};

Alter Approach ->

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    
    // Start from second-last row and move up
    for (int i = n - 2
    ; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            // Update current cell with min sum path from below row
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    
    // The minimum path sum is stored at the top of the triangle
    return triangle[0][0];
}