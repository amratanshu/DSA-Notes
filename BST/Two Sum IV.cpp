https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

Brute force is easy - u can print out the inorder traverser for this - and then solve two sum in an array using 2 pointers

For this - we have to implement an iterator - 
From the left side and from the right side both 

So we can solve the two sum - the same way we solved the two sum problem in an array - 2 pointers are basically our 2 iterators


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
    class BSTIterator {
    public:
        stack<TreeNode*> st;
        int ascending = -1;
        BSTIterator(TreeNode* root, int ascending) { 
            this->ascending = ascending;
            fillStack(root);
        }

        int next() {
            if (st.empty())
                return -1;
            TreeNode* t = st.top();
            st.pop();
            if (ascending == 1 && t->right) {
                fillStack(t->right);
            }
            else if (ascending == 0 && t->left) {
                fillStack(t->left);
            }
            return t->val;
        }

        bool hasNext() { return !st.empty(); }

        void fillStack(TreeNode* root) {
            st.push(root);
            TreeNode* temp;
            if (ascending == 1)
                temp = root->left;
            else temp = root->right;
            while (temp) {
                st.push(temp);
                if (ascending == 1)
                    temp = temp->left;
                else temp = temp->right;
            }
        }
    };
    
    bool findTarget(TreeNode* root, int k) {
        BSTIterator* asc = new BSTIterator(root, 1);
        BSTIterator* desc = new BSTIterator(root, 0);

        //bool param_2 = obj->hasNext();
        int low, high;
        if (asc->hasNext() && desc->hasNext()) {
            low = asc->next();
            high = desc->next();
        }
        while(asc->hasNext() && desc->hasNext()) {
            if (low == high) //out of bounds because we have reached the same element (no uniques)
                return false;
            if (low + high < k)
                low = asc->next();
            else if (low + high > k)
                high = desc->next();
            else if (low + high == k)  {
                return true;
            }
        }
        return false;
}};
