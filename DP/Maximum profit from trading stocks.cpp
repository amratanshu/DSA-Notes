https://leetcode.com/problems/maximum-profit-from-trading-stocks/description/

LC Premium question

Recurrence relation for the solution ->

NOTE -
In Base condition for budget - 

budget < 0 is correct condition!

Why does budget <= 0 cause issues?
When budget == 0, you are allowed to have a valid solution where you dont
buy any stocks (because you have no budget to buy them). 
The correct return value should be 0 since no profit can be made with zero budget.

However, if you change the base case to budget <= 0 and return 0, 
it might terminate the recursion prematurely in some cases where the budget was 0 after some recursive calls. 
This could affect your calculations, especially when considering valid decisions like "not taking" a stock.


class Solution {
public:
    int solve(int i, int budget, vector<int>& p, vector<int>& f) {
        if (i < 0) return 0;
        if (budget < 0) return 0;
        int take = 0;
        if (budget >= p[i]) {
            take = f[i] - p[i] + solve(i-1, budget - p[i], p, f);
        }
        int notTake = 0 + solve(i-1, budget, p, f);
        return max(take, notTake);
    }

    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size(); //no of stocks
        return solve(n-1, budget, present, future);
    }
};

Memoizing it ->

class Solution {
public:
    int solve(int i, int budget, vector<int>& p, vector<int>& f, vector<vector<int>> &dp) {
        if (i < 0) return 0;
        if (budget < 0) return 0;

        if (dp[i][budget] != -1) {
            return dp[i][budget];
        }
        int take = 0;
        if (budget >= p[i]) {
            take = f[i] - p[i] + solve(i-1, budget - p[i], p, f, dp);
        }
        int notTake = 0 + solve(i-1, budget, p, f, dp);
        return dp[i][budget] = max(take, notTake);
    }

    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size(); //no of stocks
        vector<vector<int>> dp(n, vector<int>(budget+1, -1));
        return solve(n-1, budget, present, future, dp);
    }
};