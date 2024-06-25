https://leetcode.com/problems/longest-common-subsequence/solutions/3841276/c-recursive-iterative-dp-solutions/

CONCEPT ->
f(index1, index2)
if s1[i] == s2[j]
    dp[i][j] = 1 + dp[i-1][j-1]; //match hai, toh prev + 1 hoga


MY SOLUTION WITH THE NORMAL INDEXING ->
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(), m=text2.size();
        vector<int> dp(m, 0), prev(m, 0);
        for (int i=0; i<=n-1; i++){
            for(int j=0; j<=m-1; j++){
                if (text1[i]==text2[j]) {
                    if (j-1 < 0) 
                        dp[j] = 1;
                    else
                        dp[j]=1+prev[j-1];
                }
                else {
                    if (j-1 < 0) 
                        dp[j] = prev[j];
                    else
                        dp[j]=max(prev[j], dp[j-1]);
                }
            }
            prev=dp;
        }
        return dp[m-1];
    }
    
};

People's solution - with a little different indexing scheme - 
shifted by 1 to the right side. 

here, dp[n][m] means till index=n-1 and index=m-1 in both strings. 
With this - -1 wala case ata hi nahi hai loop me. CLEANER

In the recurrence, Base case will change from 
i<0 and j<0
    return 0;

TO 

i==0 and j==0
    return 0;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(), m=text2.size();
        vector<int> dp(m+1, 0), prev(m+1, 0);
        for (int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if (text1[i-1]==text2[j-1]) dp[j]=1+prev[j-1];
                else dp[j]=max(prev[j], dp[j-1]);
            }
            prev=dp;
        }
        return dp[m];
    }
    
};