https://www.codingninjas.com/studio/problems/count-subsets-with-sum-k_3952532?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Again - similar exactly to subset with Sum k

here - we just have to do pick + notPick ka sum and store it in dp[i][j] instead of pick || notPick 

Because here we are counting "ways" or number of subsets

dp[i][j] - i is the index jahan tak dekh rahe hain, j is the target sum => 
this dp represents the number of ways we can form this target sum till i indexes of given arr.

The base cases of dp[i][0] and dp[0][arr[0]] automatically align because 
1. dp[i][0] -> means sum=0 kine tareeke se aa sakta hai - only 1 way. Choose nothing wala subset
2. dp[0][arr[0]] -> can only come when that first element itself is picked

SOLUTION Taken directly from subsets with sum K - copy pasted the one without space optimization for now

But definitely can be space optimized like we did in previous solutions !!

Did long long int and modoulo with 100000,.... because it was told to us in the question 


int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	long long int dp[n][k+1]; //meaning of the tabulation: n indexes tak sum = k wale subsets hain ya nahi
	memset(dp, 0, sizeof(dp));
	
	for (int i=0;i<n;i++)
	{
		dp[i][0] = 1;
	}

	if (arr[0] <= k)
		dp[0][arr[0]] = 1;


	for (int i=1;i<n;i++) {
		for (int j=0;j<=k;j++) {
			long long int notTake = dp[i-1][j];
			long long int take = 0;

			if (arr[i] <= j) {
				take = dp[i-1][j-arr[i]];
			}
			dp[i][j] = take + notTake;
		}
	}
	
	return dp[n-1][k]%1000000007;

}