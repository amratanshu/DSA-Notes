https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

Watch striver video = good explanation

2D DP of dp[index][target]

It is a pick and not pick problem!

if we pick - we want target - a[i] from the previous remaining array
if we dont pick - we want target only from the previous array

if any of these returns true - then we can say that such a subset is indeed present.

Here, we have converted 2d dp and space otimized it as usual to have just two 2D arrays. curr and prev.

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool> curr(k+1, false);
    vector<bool> prev(k+1, false);

    prev[0] = curr[0] = true; //because for anything, target=0 should always be true na

    if (arr[0] <= k)
        prev[arr[0]] = true; //case: if we got the target at the first place only

    for (int i=1;i<n;i++) {
         for (int j=1; j<=k; j++) {
            bool notTake = prev[j];
            bool take = false;

            if (arr[i] <= j) {
                take = prev[j-arr[i]];
            } 
            curr[j] = take || notTake;
        }
        prev = curr;
    }

    return prev[k];


}