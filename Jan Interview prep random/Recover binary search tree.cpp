https://leetcode.com/problems/recover-binary-search-tree/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days

Just inorder traversal but maintain variables for tracking previous

The first BST condition violation (sorted nahi hoga) will give the first ele
The second BST condition violation will give the second ele

Swap these now!

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
    void swap(TreeNode* a, TreeNode* b) {
        int temp;
        temp = a->val;
        a->val = b->val;
        b->val = temp;
    }
    
    TreeNode* prev;
    TreeNode* first;
    TreeNode* second;
    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }

        inorder(root->left);
        
        if (prev!=NULL && prev->val > root->val) { //violation
            if (first == NULL) {
                first = prev;
            }
            second = root;
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        if (!root) return;
        inorder(root);
        swap(first, second);
    }
};