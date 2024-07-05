https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

Can be three scenarios ->

key greater than curr key
key smaller than curr key
key equal to curr key

comments are self explanatory.

time - OH
space - OH

class Solution
{
    public:
    void solve(Node* curr, Node* &pre, Node* &suc, int key, int predDiff, int sucDiff) {
        
        if (key > curr->key) {
            //an even closer predeccesor found
            if (key - curr->key < predDiff) {
                predDiff = key - curr->key;
                pre = curr;
            }
            if (curr->right) solve(curr->right, pre, suc, key, predDiff, sucDiff);
        }
        
        else if (key < curr->key) {
            //an even closer successor found
            if (curr->key - key < sucDiff) {
                sucDiff = curr->key - key;
                suc = curr;
            }
            if (curr->left) solve(curr->left, pre, suc, key, predDiff, sucDiff);
        }
        else { //equal, pred will be in left and suc will be in right subtree
            if (curr->left) solve(curr->left, pre, suc, key, predDiff, sucDiff);
            if (curr->right) solve(curr->right, pre, suc, key, predDiff, sucDiff);
        }
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre = NULL;
        suc = NULL;
        if (!root) return;
        solve(root, pre, suc, key, INT_MAX, INT_MAX);
    }
};