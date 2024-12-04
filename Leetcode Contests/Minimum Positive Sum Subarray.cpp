https://leetcode.com/problems/minimum-positive-sum-subarray/description/

NOTE - Brute force is also accepted since constraints are small.

Approach 2 - Optimized - Sliding window with varying sizes.

Approach 3 - Optimized - Prefix sum using Sliding window.

Approach 4 - best - Sliding window with fixed size

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        int mini = INT_MAX;

        for (int k=l; k<=r; k++) {
            int sum = 0;
            for (int i=0;i<k;i++) {
                sum += nums[i];
            }

            if (sum > 0) {
                mini = min(mini, sum);
            }

            //slide window across
            for (int i=k; i<n;i++) {
                sum += nums[i];
                sum -= nums[i-k];
                if (sum > 0) {
                    mini = min(mini, sum);
                }
            }
        }
        if (mini > 0 && mini != INT_MAX) return mini;
        else return -1;
    }
};