https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description//**

Easy

class Solution {
public:
    TreeNode* solve(vector<int> &nums, int low, int high) {
        if (low > high)
            return NULL;
        int mid = (high + low)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = solve(nums, low, mid-1);
        root->right = solve(nums, mid + 1, high);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
        return solve(nums, 0, nums.size()-1);
    }
};