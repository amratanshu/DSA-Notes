https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

EASY - 

//just find the length of the longest palindromic subsequence in the string and subtract that from the len of the string

class Solution {
public:
    int minInsertions(string s) {
        //find the length of the longest palindromic subsequence in the string and subtract that from the len of the string

        int n = s.length();
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;

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
        return n - dp[n][n];
    }
};