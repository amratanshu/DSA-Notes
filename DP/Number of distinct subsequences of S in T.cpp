https://leetcode.com/problems/distinct-subsequences/description/

CONCEPT - 
Form the recurrence relation f(i, j) by this concept ->>

Think that we are traversing from the back (last characters in both strings)

If the characters match (s[i] == T[j]) - it can either mean that 
1. we have found one occurence of T in S - so this is a distinct subsequence - move both 
indexes (decrease) by 1. Because remaining letters of T (j-1 tak) ko S(i-1) me dhoondna hai ab
2. we dont pick this char, and check the remaining part of S (i-1 tak), j will remaing as is in this case

Addition of these will be the answer for equal case.

If they are not equal - then simply we have to find the full T string (j) tak in the String S (full i tak)
So the recurrence relation will look something like ->

if (chars are equal)
    f(i,j) = f(i-1, j-1) + f(i-1, j)

else
    f(i, j) = f(i-1, j)


Think about the base case !

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size() , n = t.size();
        vector<vector<double>> dp( m+1 , vector<double>(n+1,0) );
        for(int i=0;i<=m;i++) dp[i][0] = 1;
        for(int j=1;j<=n;j++) dp[0][j] = 0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                } 
          }
        }
        return (int)dp[m][n];
    }

};