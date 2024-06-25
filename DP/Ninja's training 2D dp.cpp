2D DP - easy to understand

pick and not pick kinda problem only

Doing memoization with space optimization as well.

https://www.codingninjas.com/studio/problems/ninja%E2%80%99s-training_3621003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

int ninjaTraining(int n, vector<vector<int>> &p)
{
    // Write your code here.

    if (n == 0)
        return max( max(p[0][0], p[0][1]), p[0][2]);

    int dp[3]; //ans for choosing this particular activity

    dp[0] = p[0][0];
    dp[1] = p[0][1];
    dp[2] = p[0][2];
    
    int ans;
    for (int i=1;i<n;i++) {
        int chooseA = p[i][0] + max(dp[1], dp[2]);
        int chooseB = p[i][1] + max(dp[0], dp[2]);
        int chooseC = p[i][2] + max(dp[0], dp[1]);
        
        ans = max (max(chooseA, chooseB), chooseC);

        dp[0] = chooseA;
        dp[1] = chooseB;
        dp[2] = chooseC;
    }
    return ans;
}
