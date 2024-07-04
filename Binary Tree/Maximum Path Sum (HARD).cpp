https://leetcode.com/problems/binary-tree-maximum-path-sum/

brute force - 

ans can be from two cases - 
1. root included in path - ANS = left highest sum path (continuous) + right highest sum path (continuous) + root val
2. root not included in path - ANS = max(left subtree's max path, rightsubtree's maxpath)

Just implemented that here - but this has really bad time and space complex

exceeds all time limits. 

Better solution discussed below this one

My Naive solution ->

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
    void singleDirectionMaxPath(TreeNode* curr, int &sum, int &ans) {
        ans = max(ans, sum);

        //go either left or right
        if (curr->left) {
            sum += curr->left->val;
            singleDirectionMaxPath(curr->left, sum, ans);
            sum -= curr->left->val;
        }

        if (curr->right) {
            sum += curr->right->val;
            singleDirectionMaxPath(curr->right, sum, ans);
            sum -= curr->right->val;
        }
    }

    int maxPathSum(TreeNode* root) {
        if (!root->left && !root->right) {
            return root->val;
        }
        int sum = 0;
        int ans = INT_MIN;

        //ans can be from two cases - 
        //1. root included in path - left highest sum path (continuous) + right highest sum path (continuous) + root val
        //2. max(left subtree's max path, rightsubtree's maxpath)

        int leftPathExcludingRoot = 0;
        if (root->left) {
            sum+= root->left->val;
            singleDirectionMaxPath(root->left, sum, ans);
            leftPathExcludingRoot = ans;
        }
        

        //reset ans to set rightPath
        ans = INT_MIN;
        sum = 0;
        int rightPathExcludingRoot = 0;
        if (root->right) {
            sum+= root->right->val;
            singleDirectionMaxPath(root->right, sum, ans);
            rightPathExcludingRoot = ans;
        }
        
        int val1_1 = rightPathExcludingRoot + leftPathExcludingRoot + root->val;
        int val1_2 = rightPathExcludingRoot + root->val;
        int val1_3 = leftPathExcludingRoot + root->val;
        int val2 = root->val;
        int val3 = root->left? maxPathSum(root->left): INT_MIN;
        int val4 = root->right? maxPathSum(root->right): INT_MIN;

        //the ans is whatever is the maximum of these values
        int m1 = max(val1_1, val1_2);
        int m2 = max(val1_3, val2);
        int m3 = max(val3, val4);
        return max(m1, max(m2, m3));
    }
};


Better optimisation ->

