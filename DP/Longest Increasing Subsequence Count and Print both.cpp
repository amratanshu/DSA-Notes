https://leetcode.com/problems/longest-increasing-subsequence/

CONCEPT -

f(i, prev) - index and previous index

a[prev] lets us decide whether the last element was smaller than the next element or not
To keep it strictly increasing !!

Rec Relation ->

f(i, prev) {

   //base case:
   if (i==n) //last ele ke baad, running out of elements
   {
        return 0; //we dont have anything left in the array now.
   }

    if (prev == -1 || a[i] > a[prev]) //prev = -1 matlab nothing in the subsequence till now, can always take this
        pick = 1 + f(i+1, i); //taking the current index.

    notPick = 0 + f(i+1, prev);
    
    return max(pick, notPick);
}

we'll call f(i, prev) as f(0,-1);

Time complex - 2^n - take or not take for every element
Aux Stack Space - O(n) - Recursion tree dekhogey toh n levels deep ban sakti hai..hence.

Optimise using DP

prev ranges from -1 to n-1 
We cannot store -1 = so either take a map
or just simply shift the coordinates..better !!

So now prev - 0 to n

i and prev
DP[N][N+1]

TC - O (n*n)
SC - O(n*n) (for the DP array we are making) + O(n) (for auxilliary space used in recursion calls)

But even this solution will give runtime error - because the constraints given 
are -10^5 to 10^5

Array which will be created will be 10^5 * 10^5 = 10^10 -- too heavy space

So we need to optimise it for sure. Not an option in this one.

Tabulation ->
ind -> n-1 to 0
prevIndex -> ind-1 to -1 (as the name suggests, it is PREVIOUS) follow coordinate shifting also


space optimise using curr and ahead.

TC - O(n)
SC - O(N*2)


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> next(n+1, 0), curr(n+1, 0);

        for(int i=n-1; i>=0; i--) {
            for (int prev=i-1; prev>=-1; prev--) {
                //not pick case
                int len = 0 + next[prev + 1]; //prev+1 because we shifted indexing. -1 is not possible for an array na

                if (prev == -1 || nums[i] > nums[prev]) {
                    len = max (len, 1 + next[i+1]); //pick case
                }

                curr[prev+1] = len;           
            }
            next = curr;
        }
        

        return curr[0];
    }

    
};

PRINTING ! ! ! ! ! ! ! ! 

There is another way !!
using tabluation way !! 

USING 1D DP and traversing one by one. At a step - we think for all the previous ones
and add them if we can.


1. Have a dp[n]
2. dp[i] will be the LIS ENDING AT SUBSEQUENCE. (not LIS till that, rather LIS including that element)
3. So max(all dp[i]'s') will be the answer;
Initially we will mark them all with =1; Because len=1 toh minimum hoti hi hai (that ele itself)
3. Starting from index=0 and going to n-1
4. At i, check all the previous indexes - Can the previous j be a part of susequence ending at. 
If yes - add to it. If that value is greater than what is currently stored in dp[i] already - replace. Else do nothing
If no - do nothing obviously.

TC - still O(n^2) - so this will give TLE !!!!
SC - O(n) 

REMEMBER : dp[i] in this soln stores the LIS ending at i. (includes arr[i])
This is how it is different from the previous dp solution which contained LIS till arr[i] -
including or not including.

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i=0; i<n;i++) {
            for (int prev=0; prev<i;prev++) {
                if (arr[prev] < arr[i]) {
                    dp[i] = max(dp[i], dp[prev] + 1);
                }
            }

            maxi = max(maxi, dp[i]);
        }
        return maxi;
}


But this solution will be required if we want to trace back the LIS !

Why trace back ?? PRINTING THE LIST

BACK TRACKING.

1. Create another array - name it hash [] 
Assign the index itself in hash array

so hash [0 1 2 3 4 5]

hash will keep - who was the previous index from which we came from .. HMM storing this info can make us print.

Introducing hash array for this solution above ->


#include<bits/stdc++.h>

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	int maxi = 1;
	vector<int> hash(n);
	vector<int> dp(n, 1);

	int lastIndex = 0;
	for (int i=0; i<n;i++) {
		hash[i] = i;
		for (int prev=0; prev<i;prev++) {
			if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i]) {

				dp[i] = dp[prev] + 1;
				hash[i] = prev; //whenever dp is getting updated and added by 1, add the previous to backtrack.
			}
		}

		if (dp[i] > maxi) {
			maxi = dp[i];
			lastIndex = i;
		}

	}

	vector<int> LIS;
	LIS.push_back(arr[lastIndex]); 
	while(hash[lastIndex] != lastIndex) {
		lastIndex = hash[lastIndex];
		LIS.push_back(arr[lastIndex]);
	}
	reverse(LIS.begin(), LIS.end());
	return LIS;
}

TC - O(n^2)
SC - O(n) + O(n) - LIS code ke liye O(n)


This LIS can also be done using BINARY SEARCH !
Check the Binary Search folder.
