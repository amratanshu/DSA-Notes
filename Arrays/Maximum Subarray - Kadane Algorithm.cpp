https://leetcode.com/problems/maximum-subarray/submissions/1233416023/

https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/

O(N)

KADANE'S - 
BASIC INTUITION --

If an element is making the SUM negative - dont consider it
Otherwise consider it.

Even if sum = 5 and  arr[i] is -1  - so new sum will be 4 -> consider arr[i] !!! 
because aagey wale elements me koi aisa aa sakta hai jo badha de - we are still positive at least.

NOTE - READ the Follow up details for Kadanes as well ! - in Striver article.

------------------------------------------------------------------------------------------------
KADANES approach ->
Just iterate over the array

Maintain a sum and a maximumSum

If arr[i] is positive - then we want to include it 

sum += arr[i]
if (maxi < sum)
    maxi = sum

but if the sum is negative - then that means that we need to discard the element


CODE ->

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN; // maximum sum
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            if (sum > maxi) {
                maxi = sum;
            }

            // If sum < 0: discard the sum calculated
            if (sum < 0) {
                sum = 0;
            }
        }

        // To consider the sum of the empty subarray
        // uncomment the following check:

        // if (maxi < 0) maxi = 0;

        return maxi;   
    }
};