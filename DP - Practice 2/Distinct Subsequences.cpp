https://leetcode.com/problems/distinct-subsequences/

just try to form a recurrence relation as we do in all DP questions -

f(i, j) ->

if (same char) {
    return f(i-1, j) + f(i-1. j-1)
}
else return f(i-1, j)

base case - 
dp[0][0] = 1 - one way to match
dp[0][j] = 0 - there is no way to match a non empty string t with an empty string s
dp[i][0] = 1 - there is only one way to match - delete all the extra charaters and make it null string

TO HANDLE OVERFLOW - make the dp vector to be double

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<double>> dp (n+1, vector<double>(m+1, 0));

        //initializing the base cases
        dp[0][0] = 1;
        for (int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }

        //using the recurrence relation ->
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};