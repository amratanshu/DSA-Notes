https://leetcode.com/problems/triangle/

Easy - no brainer only.

Optimised for space complexity - we're just using one vector and just creating a copy of it to look back 
because only the previous level matters.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n);
        dp[0] = triangle[0][0];
        for(int i=1;i<n;i++) {
            vector<int> temp = dp;
            dp[0] = temp[0] + triangle[i][0];
            for (int j=1; j<i;j++) {
                dp[j] = min(temp[j-1], temp[j]) + triangle[i][j];
            }
            dp[i] = temp[i-1] + triangle[i][i];
        }

        int mini = INT_MAX;
        for (int i=0;i<n;i++) {
            mini = min(dp[i], mini);
        }
        return mini;
    }
};