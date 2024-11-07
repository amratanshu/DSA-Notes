https://leetcode.com/problems/product-of-array-except-self/description/

we cant use the division operator - so calculating the full product and dividing one number does not work

O(N) algorithm is needed

Something should be calculated using prefix and suffix products - easy but - we have to do it in O(1) space
so how can we store the prefix and suffix products while modifying the input array somehow?

NOTE - dw - the Ans array does not count towards space (we dont have to solve in place!)

Do a dry run - and see the comments in the code to understand what we've done

O(N) time
O(1) space

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        //forward pass to calculate prefix sum and store in ans
        
        for (int i=1;i<n; i++) {
            ans[i] = nums[i-1] * ans[i-1];
        }

        int product = nums[n-1];
        //backward pass to calculate suffix sum (modify in nums) in place.
        for (int i=n-2; i>=0; i--) {
            int prod2 = product * nums[i];
            nums[i] = product;
            product = prod2;
        }

        //now we can calculate the product of prefix and suffix (except the elements at extreme ends)

        for (int i=1; i<=n-2; i++) {
            ans[i] = ans[i] * nums[i];
        }

        //handle the left extreme end now
        ans[0] = nums[0];
        return ans;
        

    }
};