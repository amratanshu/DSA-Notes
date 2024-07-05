https://leetcode.com/problems/binary-tree-level-order-traversal/description/

Easy ques - 

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;

            // the queue will contain elements only from the same level (==same vertical height)
            for (int i = 0; i < n; i++) {
                auto it = q.front();
                temp.push_back(it->val);
                q.pop();

                if (it->left) {
                    q.push(it->left);
                }

                if (it->right) {
                    q.push(it->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};