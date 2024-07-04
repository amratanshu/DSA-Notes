https://leetcode.com/problems/symmetric-tree/description/

Easy solution

Just traverse ulta

if going A ka left = go B ka right
if going A ka right = go B ka left

Time - O(N)
Space - O(N) - aux stack space

class Solution {
public:
    bool traverse(TreeNode* node1, TreeNode *node2) {
        if (!node1 && node2) return false;
        if (node1 && !node2) return false;
        if (!node1 && !node2) return true;
        if (node1->val != node2->val) return false;
        return traverse(node1->left, node2->right) && traverse(node1->right, node2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return traverse(root->left, root->right);
    }
};
