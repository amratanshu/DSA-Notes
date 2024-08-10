https://leetcode.com/problems/edit-distance/

RECURSION ->
My solution ->
Gives TLE !
class Solution {
public:
    int f(string &a, string &b, int i, int j) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;
        
        if (a[i] == b[j]) {
            return f(a, b, i-1, j-1);
        }
        else {
            //replace
            int replace = 1 + f(a, b, i-1, j-1);

            //delete and insert
            int delete1 = 1 + f(a, b, i-1, j);
            int delete2 = 1 + f(a, b, i, j-1);
            
            return min(replace, min(delete1, delete2));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        return f(word1, word2, n-1, m-1);
    }
};


Converting this same recursion to DP ->

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=0;i<=n;i++) {
            dp[i][0] = i;
        }

        for(int i=0;i<=m;i++) {
            dp[0][i] = i;
        }

        dp[0][0] = 0;

        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = min(1 + dp[i-1][j-1], min(1 + dp[i-1][j], 1 + dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};

Converting to 1 Dimensional DP ->

