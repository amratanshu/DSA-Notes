https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

CONCEPT: 
every transaction has a transac fees now FEE

So in the recurrence relation - har baar profit kum hoga by FEE jab transac khatam hoga

Transac kab khatam hota hai? Jab sell karte hain.

Recursion --> 

f(i, canBuy) {
    if (canBuy) {
        buy = -prices[i] + f(i+1, 0) //bought at ith, move on to the next, but we can not buy again now.
        notBuy = 0 + f(i+1, 1);

        profit = max(buy, notBuy);
    }

    else {
        sell = prices[i] + f(i+1, 1) - FEE; //can buy when we move on to the next day
        notSell = 0 + f(i+1, 0); //cannot buy again because we already own the stock.
    }
}

So easy - just copy paste the code from BS2 and do -fee in sell case. ENJOY

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);
        for (int ind=n-1; ind>=0; ind--) {
            for (int buy=0; buy<=1; buy++) {
                if (buy) //buy or not buy
                    curr[buy] = max(-prices[ind] + ahead[0], 0 + ahead[1]);
                else //sell or not sell
                    curr[buy] = max(prices[ind] + ahead[1] - fee, 0 + ahead[0]);
            }
            ahead = curr;
        }
        return ahead[1];
    }
};