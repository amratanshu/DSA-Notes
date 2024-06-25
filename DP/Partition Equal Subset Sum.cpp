SOLUTION -> 
we can modify this problem to use the exact same solution of Subset sum equal to k

Here K = sumTotal/2; (just gotta check if sumTotal is even number or not)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //this ques is same as finding a subset with sum K where K = SUMTOTAL/2; 
        if (nums.size() == 1) {
            return false;
        }
    
        int sumTotal = 0;
        for (auto i: nums) {
            sumTotal+=i;
        }

        if (sumTotal % 2 != 0)
            return false;
        
        return subsetSumToK(nums.size(), sumTotal/2, nums);
    }

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
};