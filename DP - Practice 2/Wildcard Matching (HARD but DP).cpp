https://leetcode.com/problems/wildcard-matching/description/

Form recurrence relation to solve -->

Memoize this solution ->

class Solution {
public:
    //Recurrence relation with memoization solution ->

    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if (i<0 && j<0) return true; //both strings have reached their ends
        if (i<0) {
            //s is empty - p should have only * now
            for (int k = 0; k <= j; ++k) {
                if (p[k] != '*') return false;
            }
            return true;
        };
        if (j<0) return false;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        }
        else if (p[j] == '*') {
            bool a = solve(i-1, j, s, p, dp);

            bool c = solve(i, j-1, s, p, dp);
            
            dp[i][j] = a || c;
            return a || c;
        }
        else return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
        return solve(s.length()-1, p.length()-1, s, p, dp);
    }
};