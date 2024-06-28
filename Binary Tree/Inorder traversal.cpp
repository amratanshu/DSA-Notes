time complexity - prints all elements so - O(N)
Space - O(N)

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
    void inorder(vector<int>& temp, TreeNode* root) {
        if (root->left) {
            inorder(temp, root->left);
        }

        temp.push_back(root->val);

        if (root->right) {
            inorder(temp, root->right);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> temp;
        if (root == NULL) {
            return temp;
        }

        inorder(temp, root);
        return temp;
    }
};