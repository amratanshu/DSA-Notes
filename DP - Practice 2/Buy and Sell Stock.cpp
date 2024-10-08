https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

easy recurrence -

Track the minimum price so far in a variable called MINI
int f(i) {
    take = prices[i] - MINI
    not take = f(i-1)
    return max(take, not take)
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int dp[n];
        //base case
        dp[0] = 0;

        int mini = prices[0];
        for (int i=1; i<n;i++) {
            int notTake = dp[i-1];
            int take = prices[i] - mini;
            dp[i] = max(notTake, take);
            mini = min(mini, prices[i]);
        }
        return dp[n-1];
    }
};