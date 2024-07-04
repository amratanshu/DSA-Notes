https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

Concept - it is simple pointer handling 
just remember - keep a track of the last leaf node you traversed when you traversed the left subtree

Then assign lastLeafNode->right = rightSubtree

And move on.

My solution ->

class Solution {
public:
    TreeNode* lastLeaf;
    void solve(TreeNode* curr) {
        if (curr->left == NULL && curr->right == NULL)
            lastLeaf = curr;

        if (!curr->left)  {
            if (curr->right) solve(curr->right);
        }
        else {
            TreeNode* rightSubtree = curr->right;
            TreeNode* leftSubtree = curr->left;
            curr->right = leftSubtree;
            curr->left = NULL;
            solve(leftSubtree);
            lastLeaf->right = rightSubtree;
            if (rightSubtree)
                solve(rightSubtree);
        }
    }
    void flatten(TreeNode* root) {
        if (!root)
            return;
        
        solve(root);
    }
};