https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

CONCEPT - Can have only one single stock at a time with us. Maximise profit by B, S on multiple days
Make a recurrence relation 
on (index, canBuy)

canBuy - 1 when we dont have the stock
canBuy - 0 when we own the stock

To form recursion - we follow pick and non pick concept 

At all possibilities - we buy or sell. pick or not pick.


f(i, canBuy) {
    if (canBuy) {
        buy = -prices[i] + f(i+1, 0) //bought at ith, move on to the next, but we can not buy again now.
        notBuy = 0 + f(i+1, 1);

        profit = max(buy, notBuy);
    }

    else {
        sell = prices[i] + f(i+1, 1); //can buy when we move on to the next day
        notSell = 0 + f(i+1, 0); //cannot buy again because we already own the stock.
    }
}

Base case / End of array:
(nth index) (not even n-1)--> We have to be careful because when we come to this stage - we cannot be 
still holding the stock. What if we havent sold and we are on the last day? have to sell now.

So - if we are holding some stock already - that means in total we have lost some money because
we forgot to sell. 

and if we are not holding stock already - we do nothing obviously. Why lose money by buying on last day
If we do this - definitely we wont be the max profit wala answer.

if (i==n) { //reached the end index 
    return 0; //no more money we can get from the market.
}

Time complexity - 2^n (take or not take)
Space - O(n)

We can optimize it using DP (memoization) 


DP[n][2] - canBuy can be 0 or 1 only.

TC O(N*2)
SC O(N*2) + O(N) - Aux stack space

Apply tabulation to decrease the space complexity.
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
                    profit = max((-prices[i] + dp[i+1][0]),
                    0 + dp[i+1][1]);
                }
                else{
                    profit = max((prices[i] + dp[i+1][1]),
                    0 + dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};


SPACE OPTIMISATION AGAIN: 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);
        for (int ind=n-1; ind>=0; ind--) {
            for (int buy=0; buy<=1; buy++) {
                if (buy) curr[buy] = max(-prices[ind] + ahead[0], 0 + ahead[1]);
                else curr[buy] = max(prices[ind] + ahead[1], 0 + ahead[0]);
            }
            ahead = curr;
        }
        return ahead[1];
    }
};