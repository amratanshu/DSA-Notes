https://leetcode.com/problems/painting-the-walls/description/

Similar to Knapsack

THOUGHT -> We have to assign the paid painter so that he takes up N/2 units of time - because during that time
the free painter can paint all the other remaining walls for FREE of cost. - This would be the best case greedy-ish scenario

So this is like Knapsack - Paid Painter TIME - max is N/2.


NOTE ^ The above analogical thought is NOT CORRECT!

THE problem with the above approach - we are fixing the total time taken by the paid painter as N/2?!


CORRECT SOLUTION ->

READ EDITORIAL on LC as well!

Here we can simply think of the problem as, when we paint a wall by the painter1 then we can 
skip time[i] walls (basically this time[i] no. of walls will be painted by the painter2 with zero cost).

So we can re-think the problem as select n walls from the given one so that the 
sum of the times to pain the wall(painted by free painter) + the number of wall taken (painted by painter 1) > total no. of walls to paint.

This is similar to the 0/1 Knapsack where the cost is same as weight and our bag
size is wall count. But in Knapsack we reduce the bag size by the stone size here we reduce
the wall count by the time[i] and additional -1 to reduced currently painted wall.


REAL TALK -> For every wall painted by paid painter - we use cost[i] money to paint that 1 wall 
but at the same time - free painter comes in and paints time[i] walls

So EQUATION -> 
For every ith item -> So we use cost[i] money to paint 1 + time[i] walls

This is a variation of Classic Knapsack problem

Pick or Not Pick - minimise the total cost

Recurrence will be on dp(i, remain) -> returns the min cost to paint "remain" walls when considering index i and beyond.

Base cases ->
1. no walls remaining => remain <= 0 --> return 0;
2. i == n -> you are at the end of the OPTIONS for walls to pick, but not all walls have been painted. So this path of decisions
led to not all walls being painted. (not pick not pick not pick not pick... can lead to this)


TOP DOWN DP - RECURSIVE

class Solution {
public:
    vector<vector<int>> memo;
    int n;
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        memo = vector(n, vector(n + 1, -1));
        return dp(0, n, cost, time);
    }
    
    int dp(int i, int remain, vector<int>& cost, vector<int>& time) { 
        if (remain <= 0) {
            return 0;
        }
        
        if (i == n) {
            return 1e9;
        }
        
        if (memo[i][remain] != -1) {
            return memo[i][remain];
        }
        
        
        int paint = cost[i] + dp(i + 1, remain - 1 - time[i], cost, time);
        int dontPaint = dp(i + 1, remain, cost, time);
        memo[i][remain] = min(paint, dontPaint);
        return memo[i][remain];
    }
};


BOTTOM UP DP ->

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector(n + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            dp[n][i] = 1e9;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int remain = 1; remain <= n; remain++) {
                int paint = cost[i] + dp[i + 1][max(0, remain - 1 - time[i])];
                int dontPaint = dp[i + 1][remain];
                dp[i][remain] = min(paint, dontPaint);
            }
        }
        
        return dp[0][n];
    }
};