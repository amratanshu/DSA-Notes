https://leetcode.com/problems/binary-search-tree-iterator/

For next and hasNext - We need 
Time O(1)
Space - O(H)

The solution is kind of like implementing an iterative inorder traversal solution only

Take a stack

Push the root and keep pushing the left left left elements

For Next() - pop 1 ele => Just after popping - check if the popped element has an right tree

if it does - push the right tree ka root on to the stack and again keep pushing the left left left elements of this.

This way - at any given time - max space used by stack will be O(H)

And next will take O(1) time - Amortized !

Because - if there is a right - it will take some time to do left left - and build that tree again

But all other times - it will take O(1) time

Basically - for total N elements - in the end - running next() n times will take O(N) time - which is on an avg O(1) time per node

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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        fillStack(root);
    }
    
    int next() {
        if (st.empty()) return -1;
        TreeNode* t = st.top();
        st.pop();
        if (t->right) {
            fillStack(t->right);
        }
        return t->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void fillStack(TreeNode* root) {
        st.push(root);
        TreeNode* temp = root->left;
        while (temp) {
            st.push(temp);
            temp = temp->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */