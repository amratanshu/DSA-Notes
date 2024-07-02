Simple 

https://leetcode.com/problems/maximum-depth-of-binary-tree/

NOTE - we can use level order traversal

Recursive - O(N) time and O(height) auxilliary space
Iterative - O(N) time and O(N) space for the queue we use - because the queue will have maximum number of nodes in the last level

Generally people use the Recursive solution - because recursive is bad for Skewed tree (height = N) 
and usually thats not the case ! generally height is LOGN !!

But - a slightly better and easy to write solution is using RECURRENCE

SIMPLE RECURRENCE RELATION -->
because for the root - the answer is 1 + max (f(left), f(right))


RECURRENCE SOLUTION ->
DONE!!
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max (maxDepth(root->left), maxDepth(root->right));
    }
};


This below My solution is using iterative (not the best solution!)

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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        
        queue<pair<TreeNode*, int>> q;
        int ans = INT_MIN;
        q.push({root, 1});
        while(!q.empty()) {
            auto it = q.front();
            TreeNode* node = it.first;
            int level = it.second;
            ans = max(level, ans);
            q.pop();            
            if (node->left) {
                q.push({node->left, level+1});
            }

            if (node->right) {
                q.push({node->right, level+1});
            }
        }
        return ans;
    }
};