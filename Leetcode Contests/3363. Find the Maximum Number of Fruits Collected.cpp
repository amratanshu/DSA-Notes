https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/description/

Dynamic Programming.

Observation -
Because max number of steps is fixed at n-1 => the first child can only go through the leading diagonal.


Basic recursion ->
have to memoize it later !

class Solution {
public:
    int child1x[3] = {1, 1, 1};
    int child1y[3] = {-1, 0, 1};
    int child2x[3] = {-1, 0, 1};
    int child2y[3] = {1, 1, 1};

    bool checkLimits(int x, int n) {
        if (x < n && x >= 0) return true;
        else return false;
    }
    int solve(vector<vector<int>>& fruits, pair<int, int> p, int child) {
        int n = fruits.size();
        int x = p.first;
        int y = p.second;
        if (x == n-1 && y == n-1) return fruits[n-1][n-1];
        
        int result = INT_MIN;

        if (child == 1) {
            for (int i=0;i<3;i++) {
                if (checkLimits(x + child1x[i], n) && checkLimits(y + child1y[i], n)) {
                    result = max(result, fruits[x][y] + solve(fruits, {x + child1x[i], y + child1y[i]}, child));
                }
            }
        }
        else {
            for (int i=0;i<3;i++) {
                if (checkLimits(x + child2x[i], n) && checkLimits(y + child2y[i], n)) {
                    result = max(result, fruits[x][y] + solve(fruits, {x + child2x[i], y + child2y[i]}, child));
                }
            }
        }

        return result;

    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        //p1 moves across the diagonal (only way to reach in n-1 steps)
        int n = fruits.size();
        int first = 0;
        for (int i = 0; i < n; ++i) {
            first += fruits[i][i];
            fruits[i][i] = 0;
        }      
        return first + solve(fruits, {0, n-1}, 1) + solve(fruits, {n-1, 0}, 2);


    }
};


Memoizing it ->

class Solution {
public:
    int child1x[3] = {1, 1, 1};
    int child1y[3] = {-1, 0, 1};
    int child2x[3] = {-1, 0, 1};
    int child2y[3] = {1, 1, 1};

    bool checkLimits(int x, int n) {
        if (x < n && x >= 0) return true;
        else return false;
    }
    int solve(vector<vector<int>>& fruits, pair<int, int> p, int child, vector<vector<int>> &dp) {
        int n = fruits.size();
        int x = p.first;
        int y = p.second;
        if (x == n-1 && y == n-1) return fruits[n-1][n-1];
        
        if (dp[x][y] != -1) return dp[x][y];

        int result = INT_MIN;

        if (child == 1) {
            for (int i=0;i<3;i++) {
                if (checkLimits(x + child1x[i], n) && checkLimits(y + child1y[i], n)) {
                    result = max(result, fruits[x][y] + solve(fruits, {x + child1x[i], y + child1y[i]}, child, dp));
                }
            }
        }
        else {
            for (int i=0;i<3;i++) {
                if (checkLimits(x + child2x[i], n) && checkLimits(y + child2y[i], n)) {
                    result = max(result, fruits[x][y] + solve(fruits, {x + child2x[i], y + child2y[i]}, child, dp));
                }
            }
        }

        return dp[x][y] = result;

    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        //p1 moves across the diagonal (only way to reach in n-1 steps)
        int n = fruits.size();
        int first = 0;
        for (int i = 0; i < n; ++i) {
            first += fruits[i][i];
            fruits[i][i] = 0;
        }      
        
        //NOTE - child1 is right upper corner kid according to our "child" parameter in the recursion
        //NOTE - child2 is left lower corner kid according to our "child" parameter in the recursion
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int child1 = solve(fruits, {0, n-1}, 1, dp);

        //re assign -1 in the dp array
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                dp[i][j] = -1;
            }
        }

        int child2 = solve(fruits, {n-1, 0}, 2, dp);
        return first + child1 + child2;


    }
};