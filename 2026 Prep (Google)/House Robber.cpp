https://leetcode.com/problems/house-robber/description/?envType=company&envId=google&favoriteSlug=google-three-months

CONCEPT - pick and not pick

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++) {
            int pick = nums[i] + dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick, notPick);

        }
        return dp[n-1];
    }
};