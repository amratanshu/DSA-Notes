https://leetcode.com/problems/boundary-of-binary-tree/

My solution 

3 different traversals for each thing mentioned

Zyada dimag mat lagao - just implement what is said and given in the description

My solution is without any optimisations - striver also did the same.

class Solution {
public:
    void fillLeftBound(TreeNode* root, vector<int> &lb) {
        if (!root->left && !root->right) { //leaf
            return;
        }

        lb.push_back(root->val);

        if (root->left) {
            fillLeftBound(root->left, lb);
            return;
        }
        fillLeftBound(root->right, lb);
        
    }

    void fillRightBound(TreeNode* root, vector<int> &rb) {
        if (!root->left && !root->right) { //leaf
            return;
        }

        rb.push_back(root->val);
        if (root->right) {
            fillRightBound(root->right, rb);
            return;
        }
        fillRightBound(root->left, rb);
    }

    void fillLeaves(TreeNode* root, vector<int> &leaves) {
        if (root->left) {
            fillLeaves(root->left, leaves);
        }

        if (!root->left && !root->right) { //leaf
            leaves.push_back(root->val);
            return;
        }

        if (root->right) {
            fillLeaves(root->right, leaves);
        } 
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<int> leftBoundary;
        vector<int> rightBoundary;
        vector<int> leaves;
        vector<int> ans;
        ans.push_back(root->val);

        if (!root->left && !root->right) {
            return ans;
        }
        if (root->left)
            fillLeftBound(root->left, leftBoundary);
        if (root->right)
            fillRightBound(root->right, rightBoundary);
        
        fillLeaves(root, leaves);
        reverse(rightBoundary.begin(), rightBoundary.end());
        
        //concat the 3 vectors and return
        
        for (auto i: leftBoundary)
            ans.push_back(i);

        for (auto i: leaves)
            ans.push_back(i);

        for (auto i: rightBoundary)
            ans.push_back(i);

        return ans;
    }
};