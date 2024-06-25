https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

CONCEPT ->

More than DP - this is 2 pointers.

Choose a day i and sell it on i 
We can buy from any days before i (o to i-1) - in dino me se minimum choose karna hai to maximise profit


In a single loop - keep updating mini.

Dont think this question in 2 dimensional because -> On^2 me toh brute force way hai iska!!

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;
        
        for(int i = 1; i < prices.size(); i++){
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};