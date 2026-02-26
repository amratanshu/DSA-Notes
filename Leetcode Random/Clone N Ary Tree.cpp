https://leetcode.com/problems/clone-n-ary-tree/description/

Simple recursion ->

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        int n = root->children.size();
        if (n == 0) {
            //create copyRoot and just return it
            Node* rootCopy = new Node(root->val);
            return rootCopy;
        }
        
        vector<Node*> childCopies;
        for(int i=0; i<n; i++) {
            Node* child = root->children[i];
            Node* childCopy = cloneTree(child);
            childCopies.push_back(childCopy);
        }

        return new Node(root->val, childCopies);

    }
};



