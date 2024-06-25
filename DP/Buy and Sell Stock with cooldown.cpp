https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

How to form recurrence relation:



f(i, canBuy) {
    if (canBuy) {
        buy = -prices[i] + f(i+1, 0) //bought at ith, move on to the next, but we can not buy again now.
        notBuy = 0 + f(i+1, 1);

        profit = max(buy, notBuy);
    }

    else { 
        if (i+2 <= n)
            sell = prices[i] + f(i+2, 1); //after we sell the stock - we cannot buy the very next day. 
        //So we cannot do anything on the next day basically. Go to i+2

        notSell = 0 + f(i+1, 0); //cannot buy again because we already own the stock.
        profit = max(sell, notSell);
    }
}

Base case:

if (i>=n) {
    return 0; //same as earlier.
}


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n+1][2];
        //vector<vector<int>> dp(n+1, vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    profit = max((-prices[i] + dp[i+1][0]), 0 + dp[i+1][1]);
                }
                else{
                    int sell = prices[i];
                    if (i+2 <= n) //to stop it going out of bounds
                        sell += dp[i+2][1];
                    profit = max(sell, 0 + dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

WE can further optimise this space using front1, front2 and curr. 
We will require front1 and front2 both because we require i+2 wala also.