https://leetcode.com/problems/4sum/

https://www.youtube.com/watch?v=eD95WRfh81c&feature=youtu.be

My first try - Completely same approach as 3 sum..

Just handle the OVERFLOW using long long and rest all is same - except one more loop has been added now.


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++) {
                if (j > i+1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = n - 1;
                long long sum = 0;
                while (k < l) {
                    sum = (long long) nums[i] + (long long) nums[j] + (long long) nums[k] + (long long) nums[l];
                    if (sum < target) {
                        k++;
                    } else if (sum > target) {
                        l--;
                    } else {
                        // add to answer
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        
                        ans.push_back(temp);
                        int last_high = nums[l];
                        int last_low = nums[k];
                        while (nums[k] == last_low && k < l)
                            k++;
                        while (nums[l] == last_high && k < l)
                            l--;
                    }
                }
            }
        }
        return ans;
    }
};
