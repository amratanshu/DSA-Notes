CONCEPT -
CONSECUTIVE REQUIREMNT

SUBSTRING! NOT SUBSEQUENCE!

The ans is just dependent on the last i-1, j-1

For this - remember - dp[i][j] - stores the answer for longest common substring ENDING AT ith and jth positions.
SO - dp[i][j] will not give us the answer. Rather - the max of all elements in the entire dp array will
give us the length if the LCS answer.

Hence - Remember what we are storing in dp[i][j] !!

We are not storing the longest common substring till i and j. We are storing the LCS which includes ith and jth characters.
(Ending at i and j)

When chars are equal 
    dp[i-1][j-1] + 1

If they are not equal - we'll keep them as zero.

int lcs(string &str1, string &str2){
    // Write your code here.
    int n=str1.size();
    int m=str2.size();

    int ans=0;

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=1 ; i<=n ; i++)

    {
        for(int j=1 ; j<=m; j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);

            } 

        }

    }

    return ans;

}