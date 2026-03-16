https://leetcode.com/problems/maximum-product-subarray/

Intuitive solution - Requires prefix and suffix product calculations - watch Striver video on YT

Alter Solution - Kadane's Algo or DP

At each step - store the maximum and minimum (minimum storing because if the nums[i] is negative - then we need to multiply 
    it by the minimum - which can be a negative no - which will again maximise the product further)

Handling zeroes - Reset the min prod and max prod to 1!

Watch this yt video -



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