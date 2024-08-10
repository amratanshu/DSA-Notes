https://leetcode.com/problems/target-sum/description/

https://leetcode.com/problems/target-sum/solutions/455024/dp-is-easy-5-steps-to-think-through-dp-questions/

BASIC RECURSION ->

class Solution {
public:
    int recurse(int index, int target, vector<int>& nums) {
        if (index == -1 && target == 0) return 1;
        if (index == -1) return 0;

        return recurse(index-1, target-nums[index], nums) + recurse(index-1, target+nums[index], nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return recurse(n-1, target, nums);
    }
};


DP ->

given that the sum of elements is less than = 1000
so we can shift elements accordingly ->

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2001, 0)); // -1000 to 1000 shifted to 0 to 2000

        // Base case:
        dp[0][1000] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int t = -1000; t <= 1000; t++) {
                int shiftedTarget = t + 1000;
                if (shiftedTarget - nums[i-1] >= 0 && shiftedTarget - nums[i-1] <= 2000) {
                    dp[i][shiftedTarget] += dp[i-1][shiftedTarget - nums[i-1]];
                }
                if (shiftedTarget + nums[i-1] >= 0 && shiftedTarget + nums[i-1] <= 2000) {
                    dp[i][shiftedTarget] += dp[i-1][shiftedTarget + nums[i-1]];
                }
            }
        }

        return dp[n][target + 1000];
    }
};
