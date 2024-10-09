https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

Just look at cap=2 concept from Buy and Sell Stock !!!
make cap go from 0 to K instead of 0 to 2;

SIMPLE SAME.

class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(K+1, 0));
        vector<vector<int>> curr(2, vector<int>(K+1, 0));
        for (int ind=n-1; ind>=0; ind--) {
            for (int buy=0; buy<=1; buy++) {
                for (int cap=1; cap<=K; cap++) {
                    if (buy) curr[buy][cap] = max(-prices[ind] + after[0][cap], 0 + after[1][cap]);
                    else curr[buy][cap] = max(prices[ind] + after[1][cap-1], 0 + after[0][cap]);
                }
            }
            after = curr;
        }
        return after[1][K];
    }
};

Also - if we take index and buy sell buy sell .... till 2*K (2D DP SOLUTION ONLY)

then soln - 

slightly better time complexity.

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        //denote 2 transactions using Buy Sell Buy Sell - 0 1 2 3 indexes. (buy variable)
        int dp[n+1][2*k];
        for(int i=0;i<2*k;i++) {
            dp[n][i] = 0; //base case
        }

        for (int i=n-1; i>=0; i--) {
            for (int buy=0; buy<2*k; buy++) {
                int profit = 0;
                if (buy % 2 == 0) { //buy
                    int take = -prices[i] + dp[i+1][buy+1];
                    int nottake = 0 + dp[i+1][buy];
                    profit = max (take, nottake);
                }
                else { //sell
                    int take = 0 + prices[i];
                    if (buy + 1 < 2*k)
                        take = prices[i] + dp[i+1][buy+1];
                    int nottake = 0 + dp[i+1][buy];
                    profit = max(take, nottake);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][0];
    }
};