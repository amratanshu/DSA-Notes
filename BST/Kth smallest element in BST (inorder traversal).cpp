https://leetcode.com/problems/kth-smallest-element-in-a-bst/

Just find the Inorder traversal me Kth element - they are sorted!

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root)
            return -1;

        // lets write an iterative version
        stack<TreeNode*> s;
        s.push(root);
        int count = 0;
        TreeNode* curr = root;
        while (curr != NULL || s.empty() == false) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }

            // curr is NULL now
            curr = s.top();
            s.pop();

            if (++count == k) return curr->val;
            curr = curr->right;
        }

        return -1;
    }
};