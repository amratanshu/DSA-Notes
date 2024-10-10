https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/

This uses the concept of Longest Bitonic Subsequence - which uses LIS concept only.

Think..
just find the len of the longest bitonic subsequence and subtract it from the length of the array


Mountain Array

class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        // just find the len of the longest bitonic subsequence and subtract it from the length of the array
        int n = arr.size();
        vector<int> dp1(n, 1), dp2(n, 1);
        // find LIS from left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && dp1[i] < dp1[j] + 1) {
                    dp1[i] = dp1[j] + 1;
                }
            }
        }

        // find LIS from right
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (arr[i] > arr[j] && dp2[i] < dp2[j] + 1) {
                    dp2[i] = dp2[j] + 1;
                }
            }
        }

        // find a point from where length of LIS is max from left and right
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (dp1[i] != 1 && dp2[i] != 1)
                maxi = max(maxi, (dp1[i] + dp2[i] - 1));
        }
        
        return n - maxi;
    }
};