https://leetcode.com/problems/partition-equal-subset-sum/

Concept - same as subset sum

we are just trying to find a subset whose sum = total/2

But pay attention to the edge cases - 
edge case 1. [100]
edge case 2. total sum is an odd number - simply return false in this case and dont do the dp shiz.

edge case 3: see in code

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return false;
        int total = 0;
        for (int i=0;i<n;i++) {
            total += nums[i];
        }
        if (total % 2 != 0) return false;
        int sum = total/2;

        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        for (int i=0; i<n;i++) {
            dp[i][0] = true;
        }

        //base case but this is also -- edge case 3
        //dont forget to check for this condition before assignment!
        if (nums[0] <= sum+1) dp[0][nums[0]] = true;

        for (int ind=1; ind<=n-1; ind++) {
            for (int target=1; target<=sum; target++) {
                bool notTake = dp[ind-1][target];
                bool take = false;
                if (nums[ind] <= target) take = dp[ind-1][target-nums[ind]];
                dp[ind][target] = take | notTake;
            }
        }

        return dp[n-1][sum];
    }
};