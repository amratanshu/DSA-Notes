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


