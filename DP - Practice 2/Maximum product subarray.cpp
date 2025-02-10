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

Smoother iterative solution ->
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0], curMax = nums[0], curMin = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(curMax, curMin);
            curMax = max(nums[i], curMax * nums[i]);
            curMin = min(nums[i], curMin * nums[i]);
            maxProd = max(maxProd, curMax);
        }
        return maxProd;
    }
};


Recursive ->

class Solution {
public:
    int max_=INT_MIN;
    map<int,map<int,long int>> dp;
    int solve(int temp,vector<int>& nums,int i)
    {
        if(i==nums.size()-1)
        {
            return max(max_,temp*nums[i]);
        }
        if(dp[temp][i]!=0)return dp[temp][i];
        int res1=solve(temp*nums[i],nums,i+1);
        int res2=solve(1,nums,i+1);
        max_=max(max(temp*nums[i],res1),max(max_,res2));
        return dp[temp][i]=max_;
    }
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        return solve(1,nums,0);
    }
};