GOOD HARD question

https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

TRICK : To make minimum insertions - I need to know what palindrome subsequence are present in the string already

So whatever characters remaining after the longest palindromic subsequence - are the ones we 
need to insert at different places.


class Solution {
public:
    int minInsertions(string s) {
        return s.length() - longestPalindromeSubseq(s);        
    }

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