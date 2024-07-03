https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

Naive solution

find both nodes - O(N) for each node
Store their paths in some data stru. - O(N) for each node

Compare and find the LCA.

This will take O(2N) time and O(2N) space

OPTIMISE on space ..because for eg - path 1 5 2 4 and path 1 5 3 .. we are storing 1 5 twice
Can we do it by without having a data st of O(N)?

While traversging - simple recursive DFS traversal --

dont add to a DS

Rather, write a recursive func - which, for each node - finds which ele (p or q) is in its subtree

If both are there in this subtree - the curr node is returned because it becomes the LCA

Null is returned if p and q both are not found in this subtree.

See Striver screenshot to understand better

TIME - O(N)
SPACE - O(N) - aux stack space for recursion - in terms of skew tree

My solution - 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: 

    TreeNode* find(TreeNode* curr, TreeNode* p, TreeNode* q) {
        if (curr == p || curr == q)
            return curr;
        
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        if (curr->left) {
            left = find(curr->left, p, q);
        }

        if (curr->right) {
            right = find(curr->right, p, q);
        }

        //if both found in this subtree - return curr - because that will be the LCA.
        if ((left == p && right == q) || (left == q && right == p)) {
            return curr;
        }

        if (!left)
            return right;
        else
            return left;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return root;

        if (p == q)
            return p;
        
        return find(root, p, q);
    }
};