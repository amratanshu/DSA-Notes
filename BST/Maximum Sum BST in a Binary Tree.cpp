https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/

Concept -

For each node - to compute whether the below tree is a bst or not - we need a few things
1. if left tree is bst
2. if right tree is bst

and if they are both bsts - and we need to check if the current node also makes a bigger bst - 
then we need the highest value in the left tree and lowest value in the right tree

3. highest val in this tree
4. lowest val in this tree

So - why not make a data structure which can return all of these things - using a STRUCT

class Solution {
public:
    
    struct Info {
        bool isBst = true;
        int sum = 0;
        int highest = INT_MIN;
        int lowest = INT_MAX;
    };

    int finalAns = INT_MIN;
    Info solve(TreeNode* curr) {
        //leaf node
        if (curr == NULL) {
            Info i;
            return i;
        }
        Info left = solve(curr->left);
        Info right = solve(curr->right);

        Info ans;
        
        //current tree is also a bst
        if (left.isBst && right.isBst && curr->val > left.highest && curr->val < right.lowest) {
            ans.isBst = true; //redundant
            ans.sum = left.sum + right.sum + curr->val;
            ans.highest = max(curr->val, right.highest);
            ans.lowest = min(curr->val, left.lowest);
        }
        else {
            ans.isBst = false;
            ans.sum = max(left.sum, right.sum);
        }

        finalAns = max(finalAns, ans.sum);
        return ans;

    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        if (finalAns < 0) return 0;
        return finalAns;
    }
};