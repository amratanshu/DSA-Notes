https://leetcode.com/problems/longest-palindromic-subsequence/description/

just reverse the string and find s and reverse s ka longest common subsequence.

easy peazy

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //just reverse a string and find its longest common subsequence
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= n; ind2++) {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }

        return dp[n][n];
    }
};