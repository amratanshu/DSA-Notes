https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/1310933133/

If u do a manual dry run intuitively -

can be broken down to 3 cases ->

1. p and q are in different subtrees of curr. Means curr is the LCA
2. p and q are both in left subtree of curr
3. p and q are both in right subtree of curr
4. if any of p and q are found - return it. Because - doosra wala ab tak nahi mila - means is found wale
ke sub tree me hi hoga.
Else ans return ho chuka hota ab tak

Time - O(H)
Space - O(H)

class Solution {
public:
    TreeNode* solve(TreeNode* curr, TreeNode* p, TreeNode* q) {
        //0. if found, then return it
        if (curr == p || curr == q) return curr;
        //1. if they are in different subtrees of curr
        if (p->val < curr->val && q->val > curr->val || p->val > curr->val && q->val < curr->val) return curr;
        
        //2. both are in same subtree - left or right
        if (p->val < curr->val && q->val < curr->val) return solve(curr->left, p, q);
        if (p->val > curr->val && q->val > curr->val) return solve(curr->right, p, q);
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};