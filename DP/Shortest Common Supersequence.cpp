https://leetcode.com/problems/shortest-common-supersequence/description/

CONCEPT: If we have two strings "dabac" and "cabpcd"

LCS is "abc"

We have to keep LCS abc as it is and then arrange the letters from str1 an str2 between
LCS in the same pattern as they appear in the strings.

The last loop does that. Brute force way only. Nothing special.

First part of the program is just finding the longest common longest common subsequence.


class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        int dp[n+1][m+1];
        string lcs = "";
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else 
                    dp[i][j] = max(
                        dp[i-1][j],
                        dp[i][j-1]
                    );
            }
        }

        //we have the DP. Now we can backtrack to find the LCS string, done in previous questions already.
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (s1[i-1] == s2[j-1]) {
                //these characters belong to the LCS so they will not be marked
                lcs = s1[i-1] + lcs;
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
        
        //here we have the LCS string
        //we need chars from S1 and S2 in the same places as they are alongside LCS.

        string result = "";
        i=0; 
        j=0;
        for (char ch:lcs) {
            //keep increasing the pointers for respectives strings till you find the char X of the LCS in these strings.
            while(s1[i] != ch) {
                result += s1[i];
                i++;
            }
            while(s2[j] != ch) {
                result += s2[j];
                j++;
            }

            result += ch; //when we are done adding the non LCS chars from S1, we can add the LCS character we are on.
            i++;
            j++;
        }

        //the characters after LCS in both strings are left now. We can simply take them out using substring from the index they were stopped.
        return result + s1.substr(i) + s2.substr(j);
    }
};