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

bool isBalanced(Node* root) {
        // Check if the tree's height difference
        // between subtrees is less than 2
        // If not, return false; otherwise, return true
        return dfsHeight(root) != -1;
    }

    // Recursive function to calculate
    // the height of the tree
    int dfsHeight(Node* root) {
        // Base case: if the current node is NULL,
        // return 0 (height of an empty tree)
        if (root == NULL) return 0;

        // Recursively calculate the
        // height of the left subtree
        int leftHeight = dfsHeight(root->left);

        // If the left subtree is unbalanced,
        // propagate the unbalance status
        if (leftHeight == -1) 
            return -1;

        // Recursively calculate the
        // height of the right subtree
        int rightHeight = dfsHeight(root->right);

        // If the right subtree is unbalanced,
        // propagate the unbalance status
        if (rightHeight == -1) 
            return -1;

        // Check if the difference in height between
        // left and right subtrees is greater than 1
        // If it's greater, the tree is unbalanced,
        // return -1 to propagate the unbalance status
        if (abs(leftHeight - rightHeight) > 1)  
            return -1;

        // Return the maximum height of left and
        // right subtrees, adding 1 for the current node
        return max(leftHeight, rightHeight) + 1;
    }