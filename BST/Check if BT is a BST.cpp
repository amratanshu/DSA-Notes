https://leetcode.com/problems/validate-binary-search-tree/

Normal recursive solution would look like this -

But this would not pass all cases 

Why? because - there can be cases like - root = [INT_MAX, INT_MIN] - which will return a false but should return a true

This is because - our actual upper limit should allow the INT MAX value and technically - the upper limit is 
INT MAX + 1;

Similarly INT_MIN - 1

Code with edge case FAIL -
class Solution {
public:
    bool solve(TreeNode* root, int LL, int UL) {
        if (root->val >= UL || root->val <= LL) return false;
        bool left = true, right = true;
        if (root->left)
            left = solve(root->left, LL, root->val);
        if (root->right)
            right = solve(root->right, root->val, UL);
        if (left && right) return true;
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, INT_MIN, INT_MAX);
    }
};

CODE with edge case pass - 

handling the numbers using long ->

class Solution {
public:
    bool solve(TreeNode* root, long LL, long UL) {
        if ((long) root->val >= UL || (long)root->val <= LL) return false;
        bool left = true, right = true;
        if (root->left)
            left = solve(root->left, LL, root->val);
        if (root->right)
            right = solve(root->right, root->val, UL);
        if (left && right) return true;
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }
};

For the above solution -
Time - O(N)
Space - O(N)

More optmisation -