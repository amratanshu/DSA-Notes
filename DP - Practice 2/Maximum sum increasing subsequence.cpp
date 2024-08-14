https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

Recursive solution to start with ->

Just like in LIS - just use sum here instead of len for the recursive answer.

But this will be TLE. So have to use DP now.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int f(int prev, int ind, int arr[], int n) {
	    if (ind == n) return 0;
	    
	    //not take case
	    int sum = f(prev, ind + 1, arr, n);
        if (prev == -1 || arr[prev] < arr[ind]) {
            sum = max(sum, arr[ind] + f(ind, ind + 1, arr, n));
        }
        return sum;
	}
	
	int maxSumIS(int arr[], int n)  
	{  
        return f(-1, 0, arr, n);
	}  
};


Dp solution ->

ublic:
    int maxSumIS(int arr[], int n) {
        // DP table to store results of subproblems
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // Fill the DP table in bottom-up manner
        for (int ind = n; ind >= 0; ind--) {
            for (int prev = ind; prev >= 0; prev--) {
                if (ind == n) continue;
                
                // Not take case
                int sum = dp[ind+1][prev];

                // Take case
                // Adjusted prev indexing: prev-1 corresponds to the correct element in arr
                if (prev == 0 || arr[prev-1] < arr[ind]) {
                    sum = max(sum, arr[ind] + dp[ind+1][ind+1]);
                }

                // Correct the dp table indexing
                dp[ind][prev] = sum;
            }
        }

        return dp[0][0];  // Return dp[1][0] as it corresponds to the correct calculation
    }

