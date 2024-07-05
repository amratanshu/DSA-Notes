Easy - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/1310440507/

My solution ->

Beats 100%
Both time and space O(N)

class Solution {
public:
    TreeNode* solve(vector<int>& pre, int low, int high) {
        if (low > high) return NULL;
        TreeNode* root = new TreeNode(pre[low]);

        if (low == high) return root;
        //find an ele more than the root
        for (int i=low+1; i<=high; i++) {
            if (pre[i] > pre[low]) {
                root->left = solve(pre, low+1, i-1);
                root->right = solve(pre, i, high);
                break;
            } else {
                if (i == high) //no ele greater than root, so no right subtree found
                    root->left = solve(pre, low+1, high);
            }
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0)
            return NULL;
        
        return solve(preorder, 0, preorder.size()-1);
    }
};

Striver solution ->
