https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

CONCEPT -

Adding on to B&S2 - here, we can add another variable in the recursion to track
the number of Buys (cap on the transactions)

cap -- only if 1 transactions gets completed. Buy and Sell both.
So when se sell - that's when cap decreases by 1. Not while buying. Buying is half a transaction.'

We need AT MAX 2 transactions

We will call f(0, 1, 2) to get the answer

f(i, canBuy, cap) {
    if (canBuy) {
        buy = -prices[i] + f(i+1, 0, cap);
        notBuy = 0 + f(i+1, 1, cap);
        return max(buy, notBuy);
    }
    else {
        sell = prices[i] + f(i+1, 1, cap-1);
        notSell = 0 + f(i+1, 0, cap);
        return max(buy, notBuy);
    }
}

Base cases:

if (i==n) {
    return 0; //cant get anything from the market. no transaction anymore
}
if (cap == 0) {
    return 0; //cant get anything from the market. no transaction anymore
}

So basically DP[N][2][3];

For Memoization :
TC = O(n*2*3)
SC = O(N*2*3) + O(n) - this second thing is the auxilliary stack space of the recursion.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int ind=n-1; ind>=0; ind--) {
            for (int buy=0; buy<=1; buy++) {
                for (int cap=1; cap<=2; cap++) {
                    if (buy) dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
                    else dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
                }
            }
        }
        return dp[0][1][2];
    }
};


More space optimization -->

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for (int ind=n-1; ind>=0; ind--) {
            for (int buy=0; buy<=1; buy++) {
                for (int cap=1; cap<=2; cap++) {
                    if (buy) curr[buy][cap] = max(-prices[ind] + after[0][cap], 0 + after[1][cap]);
                    else curr[buy][cap] = max(prices[ind] + after[1][cap-1], 0 + after[0][cap]);
                }
            }
            after = curr;
        }
        return after[1][2];
    }
};

There can be slightly better solution than this also !

So this above solution was O(n * 2 * 3)

We can have a solution with O(n*4) --how?

We know there can be 2 transactions
OR 4 operations in this order --> B S B s

mark these operations from 0 to 3. 

0 1 2 3
B S B s

If even : means Buy
If odd: means Sell

We can add one whenever we do an operation number.

Slight change only. DIY.

DIY == solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        //denote 2 transactions using Buy Sell Buy Sell - 0 1 2 3 indexes. (buy variable)
        int dp[n+1][4];
        for(int i=0;i<4;i++) {
            dp[n][i] = 0; //base case
        }

        for (int i=n-1; i>=0; i--) {
            for (int buy=0; buy<=3; buy++) {
                int profit = 0;
                if (buy % 2 ==0) { //buy
                    int take = -prices[i] + dp[i+1][buy+1];
                    int nottake = 0 + dp[i+1][buy];
                    profit = max (take, nottake);
                }
                else { //sell
                    int take = 0 + prices[i];
                    if (buy + 1 < 4)
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