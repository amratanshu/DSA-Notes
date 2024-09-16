https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int n = coins.size();
        // Space Optimised
        vector<int> prev(sum + 1, -1), curr(sum + 1, -1);
        for (int target = 0; target <= sum; target++) {
            if (target % coins[0] == 0)
                prev[target] = target / coins[0];
            else
                prev[target] = 1e9;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= sum; target++) {
                int notTake = 0 + prev[target];
                int take = INT_MAX;
                if (coins[ind] <= target) {
                    take = 1 + curr[target - coins[ind]];
                }
                curr[target] = min(take, notTake);
            }
            prev = curr;
        }
        if (prev[sum] >= 1e9) {
            return -1;
        } else
            return prev[sum];
    }
};