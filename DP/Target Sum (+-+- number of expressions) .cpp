CONCEPT =>

1. There can be negative target - so we cant use a int[][] dp= Instead we'll use a map<pair<int,int>> dp
2. 
    int plus = memo(nums, target - nums[index], index-1, dp);
    int minus = memo(nums, target + nums[index], index+1, dp);
    dp[{index, target}] = plus + minus;


My solution ->


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        //here, we somehow have to handle the fact that target can be negative.
        //so we can use MAP of Pair <i, j> instead of an array to store DP.

        int n=nums.size();

        map<pair<int, int>, int> dp;
        return memo(nums, target, n-1, dp);
    }

    int memo(vector<int>& nums, int target, int index, map<pair<int, int>, int>& dp) {
        // if (index < 0)
        //     return 0;

        if (index==0) {
            if (target==0 && nums[index]==0) {
                return 2; //both + and - wale cases will work.
            }
            if (abs(nums[index]) == abs(target)) {
                return 1;
            }
            else return 0;
        }

        if (dp.find({index, target}) != dp.end()) //already present in dp memo
        {
            return dp[{index, target}];
        }

        int plus = memo(nums, target - nums[index], index-1, dp);
        int minus = memo(nums, target + nums[index], index-1, dp);
        dp[{index, target}] = plus + minus;
        return dp[{index, target}];
    }
};