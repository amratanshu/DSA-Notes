https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

This has a DP solution

But here is the the Kadane's algorithm type approach

variables - 
maxi - shows max profit till now
buyPrice - keeps in store the lowest number till now.

Array exampple - 

[ 7 1 5 3 6 4 0 2]
At first the buy price is set to 1. And then iterating till 0, we find that the maximum profit is 5.

Then we land at 0 - and we're like - lets try to keep this as buy price now - because for any Sell after this day - 
we will make more profit in selecting 0 as buying day instead of 1. Hence - this single pass algo works so nicely

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxi = 0;
        int buyPrice = prices[0];

        for (int i=1; i<prices.size(); i++) {
            if (prices[i] < buyPrice) {
                buyPrice = prices[i];
                continue;
            }

            if (maxi < prices[i] - buyPrice) {
                maxi = prices[i] - buyPrice;
            }
        }
        return maxi;
    }
};