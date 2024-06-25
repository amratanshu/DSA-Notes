https://leetcode.com/problems/edit-distance/

S1 ko S2 banana hai by doing 3 ops - Insert - Delete - Replace

Think of recursion from last index in both strings like we usually do.

We'll come to base case later

First think of normal case -

S1 H O R S E

S2 R O S 

Recurrence Relation

if (S1[i] == S2[j]) {
    return 0 + f(i-1, j-1); //match hi kar raha hai so we just have to make the previous parts 
    //of the strings equal now --- S1 remaining convert to S2
}

else {
    //We'll do an insert of the item we require (obviously), so we automatically add 
    //S to the end of S1. Now both have S in the end. So we need to convert the remaining S1 
    //(Which is the complete original S1 and remaining S2 - last letter hatake because vo toh 
    //match karwa dia na)
    insert = 1 + f(i, j-1); 

    //we delete the unrequired item from the S1 string, need to compare the remainings
    delete = 1 + f(i-1, j); 

    //we replace the different char with the required one in S1. Now dono ke remaining parts
    //compare honge obviously.
    replace = 1 + f(i-1,j-1);
}


Base case for this Recursion Relation :

Either of the string can get over 

What does that mean??
if S1 is over i.e if (i<0) {
    //means to make S1 equal to S2 - we have to insert jitne bhi elements S2 me hain.
    return j+1;
}

if S2 is over i.e if (j<0) {
    //means we have to delete everything remaining in S1 to make it an empty string
    return i+1;
}


CODE: 
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.length();//first word length
        const int n = word2.length();//second word length
        
        // dp[i][j] := min # of operations to convert word1[0..i) to word2[0..j)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        //base case 1
        for (int i = 1; i <= m; ++i)
            dp[i][0] = i;

        //base case 2
        for (int j = 1; j <= n; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1])//same characters
                    dp[i][j] = dp[i - 1][j - 1];//no operation
                else
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                                //replace       //delete        //insert
            }
        }
        return dp[m][n];
    }
};