https://leetcode.com/problems/number-of-longest-increasing-subsequence/

In LIS - we did two ways
1. normal DP way - dp[i] means LIS till that index
2. the single traversal way (with prev coming from 0 to i-1 everytime) - 
    where dp[i] means LIS ending at that subsequence. This is the subtle difference!



First approach which comes to mind - 
Why don't we use these dp's arrays and count the number of occurences of final LIS answer - 
Is that correct?? NO!

Because - 1 3 5 4 7
has 2 LIS - [1 3 4 7] and [1 3 5 7] - both ending at LIS

So both our approaches will have only dp[lastIndex] = 4. So our way will return 1. HENCE WRONG !!

Solution: 
Our recurrence relation from LIS will change now. We have to maintain another 
array count[i] which tells us the count of LIS's ' till that point

Do a dry run - you'll understand better'

In the pick case ->
    if (arr[i] > arr[j] && dp[j]+1 < dp[i])
    {
        dp[i] = 1 + dp[j]; 
        count[i] = count[j]; ///this is the new line 
    }
    else if (arr[i] > arr[j] && dp[j] + 1 == dp[i]) {
        count[i] += count[j]; ///this is the new line 
        //pichle wale me hi agar 3 LIS hain toh arr[i] milake count + 3 honge 
    } 


Dry run will look something like this ->

arr => [1 5 4 3 2 6 7 10 8 9]
dp =>  [1 2 2 2 2 3 4 ..]
count =[1 1 1 1 1 4 4 ..]


LIS of value 6 is 3 with count 4 {(1,5,6),(1,4,6),(1,3,6),(1,2,6)} and 
LIS of value 7 is 4 with count 4 {(1,5,6,7),(1,4,6,7),(1,3,6,7),(1,2,6,7)}

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
       int n = nums.size();

        vector<int> dp(n,1) , cnt(n,1);

        int maxi = 1;
        //same as LIS
        for(int i = 0 ; i < n ; i++){
            for(int prev = 0 ; prev < i ; prev++){
                if(nums[prev] < nums[i] and dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                    cnt[i] = cnt[prev]; // if this condition , then only copy pate cnt
                }
                else if(nums[prev] < nums[i] and dp[prev] + 1 == dp[i]){
                    cnt[i]+=cnt[prev]; // if this condition, then add
                }
            }
            maxi = max(maxi,dp[i]);
        }

        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            if(dp[i] == maxi) ans+=cnt[i];
        }

        return ans;
    }
};

