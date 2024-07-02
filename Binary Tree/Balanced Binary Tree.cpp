https://leetcode.com/problems/balanced-binary-tree/

Easy concept

Just finding height.

This is a naive solution

Time - O(N) - based on finding the height

Striver solution also stated below --

Better solution is below
Food for though - IMPROVEMENT - how to return early? when we've found an unbalanced pair?

/** 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, bool &ans) {
        if (!root)
            return true;
        
        int lh = solve(root->left, ans);
        int rh = solve(root->right, ans);

        if (abs(lh - rh) > 1) {
            ans = false;
        }
        
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        bool ans = true;
        solve(root, ans);
        return ans;
    }
};




Just edit this height finding solution slightly

I require a function which calculates the height also but - if it is unbalanced i need to return something else

So i propose -
1. this function will return int i.e the height of the tree if left and right are balanced
2. if they are unbalanced - i will return a -1

His code - 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root) {
        if (!root)
            return true;
        
        int lh = solve(root->left);
        int rh = solve(root->right);

        if (lh == -1 || rh == -1)
            return -1;

        if (abs(lh - rh) > 1) {
            return -1;
        }
        
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        if (solve(root) == -1)
            return false;
        return true;
    }
};