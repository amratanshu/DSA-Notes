https://leetcode.com/problems/diameter-of-binary-tree/

My Double recursive solution - not the most effecient

concept - 

1. If the root is included in the path - the longest will be left subtree height + right subtree height
2. If the root is not included, it will be max of leftSubtree diameter and rightSubtree diameter

Time - O(N^2) - 2 recursions
Space - 

Better solution given further below

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

    int height(TreeNode* root) {
        if (!root)
            return 0;
        return max(1 + height(root->left), 1 + height(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        
        //if root is included
        int ans1 = height(root->left) + height(root->right);
        int ans2 = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));

        return max(ans1, ans2);
    }
};

What if we can do this in single recursion pass or something

options ->
You can maintain a Map with TreeNode as a key and store all the heights.

So that way - u dont have to repeatedly calculate height and just do ONE recursion for assigning all heights 
and ONe recursion for finding out the diameter

OR simply ---

Striver - 

We know how to find the height of a tree
Using the 1 + max (lh, rh) wala recursive solution

In this solution, we already have access to the lh and rh..

Just decalre a maxi global var and do maxi = max(maxi, lh + rh) to find the ans. 

BASICALLY - it boils down to -- 
At every node - if we do maxi = max (maxi, lh + rh) - we will have our answer

Because that diameter find karne wala recursive function essentially does nothing - it just terminates 
somewhere this lh + rh (root including) wala answer hi

So - code -

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

    int heightAndDia(TreeNode* root, int &ans) {
        if (!root)
            return 0;
        
        int lh = heightAndDia(root->left, ans);
        int rh = heightAndDia(root->right, ans);

        ans = max(ans, lh + rh);
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int ans = INT_MIN;
        heightAndDia(root, ans);
        return ans;
    }
};