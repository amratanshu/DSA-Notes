https://leetcode.com/problems/invert-binary-tree/description/
https://www.geeksforgeeks.org/problems/mirror-tree/1

TOO EASY Solution using recursion

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if (!node) return;
        if (!node->left && !node->right) return;
        
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }
};