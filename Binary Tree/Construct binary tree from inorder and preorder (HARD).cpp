https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


Concept -

preorder[0] is always the root

Search for this root in inorder. Suppose it is at index i

Count elements before that index i.

Everything before index i is the left subtree ka inorder

Everything after index i is the right subtree ka inorder

So now we know count of eles in left subtree and right subtree

In Preorder vector - Root ke baad countLeft elements are the left subtree and uske baad wale saare are the right subtree

Just do a recursion using this information

It is just a game of indexes now

TIME - O(N)
SPACE - O(N)

My solution - 

class Solution {
public:
    TreeNode* solve(vector<int>& preorder, pair<int, int> rangePre, vector<int> &inorder, pair<int, int> rangeInorder) {

        int preLow = rangePre.first;
        int preHigh = rangePre.second;
        int inLow = rangeInorder.first;
        int inHigh = rangeInorder.second;
        
        //bounds check here -
        if (preLow > preHigh || inLow > inHigh)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preLow]); //first element of pre is the root

        int leftSubtreeCount = 0;
        //find this root in Inorder -
        for (int i=inLow; i<=inHigh; i++) {
            if (inorder[i] == root->val)
                break;
            leftSubtreeCount ++;
        }

        TreeNode* left = solve(preorder, {preLow + 1, preLow + leftSubtreeCount}, inorder, {inLow, inLow + leftSubtreeCount - 1});
        TreeNode* right = solve(preorder, {preLow + leftSubtreeCount + 1, preHigh}, inorder, {inLow + leftSubtreeCount + 1, inHigh});
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL;
        
        int n = preorder.size(); //same as inorder.size

        //RangePre is the range of indexes from which we have to take preorder traversal (inclusive)
        TreeNode* root = solve(preorder, {0, n-1}, inorder, {0, n-1});

        return root;
    }
};