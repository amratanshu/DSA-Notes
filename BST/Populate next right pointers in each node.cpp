https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

Easy if u can think of the recursion

Draw a 3-4 level ka tree on paper and see whats happening first (do manually, not code wise)

You will see that we always have to connect the roots of 2 small trees

Just figure out those small trees and you will figure out the recursion

O(N) - time
O(1) space - if we ignore aux time space 

class Solution {
public:
    void interconnect(Node* n1, Node* n2) {
        //connect their roots

        n1->next = n2;
        if (n1->right) {
            interconnect(n1->left, n1->right);
            interconnect(n1->right,n2->left);
            interconnect(n2->left, n2->right);
        }
    }
    Node* connect(Node* root) {
        if (!root)
            return root;
        
        if (root->left) { //right subtree must also be there because it is a perfect binary tree
            interconnect(root->left, root->right);
        }
        return root;
    }
};