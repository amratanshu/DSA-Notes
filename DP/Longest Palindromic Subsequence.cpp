https://leetcode.com/problems/longest-palindromic-subsequence/description/

TRICK CONCEPT -> Strings reverse karo aur unka Longest Common Subsequence nikal lo

class Solution {
public:
  int longestPalindromeSubseq(string s) {
        string b = s;
        reverse(b.begin(), b.end());
        return longestCommonSubsequence(s, b);
    }
    int t[1002][1002];
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        for (int i = 0; i<=n; i++){
            for (int j = 0; j<=m; j++){
                if (i == 0 || j == 0){
                    t[i][j] = 0;
                }
            }
        }
        for (int i = 1; i<=n; i++){
            for (int j = 1; j<=m; j++){
                if (text1[i-1] == text2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
};


OR - to do it directly - just traverse the other string in the opposite order (m to 1 instead of 1 to m)

