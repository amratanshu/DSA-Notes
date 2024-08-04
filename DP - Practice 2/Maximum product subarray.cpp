https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<double> maxDP(n);
        vector<double> minDP(n);
        maxDP[0] = minDP[0] = (double) nums[0];
        int result = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                maxDP[i] = max(minDP[i-1] * nums[i], (double) nums[i]);
                minDP[i] = min(maxDP[i-1] * nums[i], (double) nums[i]);
            } else {
                maxDP[i] = max(maxDP[i-1] * nums[i], (double) nums[i]);
                minDP[i] = min(minDP[i-1] * nums[i], (double)nums[i]);
            }

            result = max(result, (int) maxDP[i]);
        }
        return result;
    }
};