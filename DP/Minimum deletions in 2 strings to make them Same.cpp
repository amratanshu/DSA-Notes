https://leetcode.com/problems/delete-operation-for-two-strings/description/

CONCEPT: LCS same hai, baaki bache hue characters ko delete kar do. ban gayi same string.

class Solution {
public:
    int minDistance(string word1, string word2) {
        int lcs = longestCommonSubsequence(word1, word2);
        return (word1.size()-lcs) + (word2.size()-lcs);
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