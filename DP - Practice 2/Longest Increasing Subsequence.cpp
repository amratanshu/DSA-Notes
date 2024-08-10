https://leetcode.com/problems/longest-increasing-subsequence/description/


NOTE: The DP solution for LIS is not the most optimal one - it is O(N^2) and cant be used
in a lot of tests

LIS can be done using Binary search!! optimally ! check the binary search folder - https://www.youtube.com/watch?v=on2hvxBXJH4&t=52s

Striver DP solution ->

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest increasing subsequence
int getAns(int arr[], int n, int ind, int prev_index, vector<vector<int>>& dp) {
    // Base condition
    if (ind == n)
        return 0;
        
    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];
    
    int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);
    
    int take = 0;
    
    if (prev_index == -1 || arr[ind] > arr[prev_index]) {
        take = 1 + getAns(arr, n, ind + 1, ind, dp);
    }
    
    return dp[ind][prev_index + 1] = max(notTake, take);
}

int longestIncreasingSubsequence(int arr[], int n) {
    // Create a 2D DP array initialized to -1
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    
    return getAns(arr, n, 0, -1, dp);
}

Other solution off of leetcode ->

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        //stores the LIS till that index
        vector<int> dp(n, 1);
        int ans = INT_MIN;
        for (int i=0; i<n; i++) {
            for(int j=0;j<i; j++) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans == INT_MIN? 1: ans;
    }
};



My solution - do a dry run and create the 2D dp table on paper to understand more -


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp (n, vector<int>(m, 0));
        int ans = INT_MIN;
    
        for(int i=0;i<n; i++) {
            for (int j=0;j<m;j++) {
                if (text1[i] == text2[j]) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1 + 0;
                    }
                    else dp[i][j] = 1 + dp[i-1][j-1]; //take
                }
                else { //not take
                    if (i == 0 && j) dp[i][j] = dp[i][j-1];
                    else if (i && j == 0) dp[i][j] = dp[i-1][j];
                    else if (i && j) dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};