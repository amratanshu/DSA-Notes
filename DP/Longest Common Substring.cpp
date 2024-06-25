CONCEPT -
CONSECUTIVE REQUIREMNT

SUBSTRING! NOT SUBSEQUENCE!

The ans is just dependent on the last i-1, j-1

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