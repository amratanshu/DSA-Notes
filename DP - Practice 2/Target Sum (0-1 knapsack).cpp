https://leetcode.com/problems/target-sum/description/

https://leetcode.com/problems/target-sum/solutions/455024/dp-is-easy-5-steps-to-think-through-dp-questions/

BASIC RECURSION ->

class Solution {
public:
    int recurse(int index, int target, vector<int>& nums) {
        if (index == -1 && target == 0) return 1;
        if (index == -1) return 0;

        return recurse(index-1, target-nums[index], nums) + recurse(index-1, target+nums[index], nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return recurse(n-1, target, nums);
    }
};


DP ->

