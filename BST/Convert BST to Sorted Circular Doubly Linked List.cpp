https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

We want to do this in place

And use the left and right pointers for previous and next pointers in the DLL

For this - just write the INORDER traversal ka iterative code and keep track of prev and top and mark the linked list

Also keep track of first and last to make it circular

My solution ->

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return NULL;
        
        stack<Node*> s;
        Node* curr = root;
        Node* prevPopped = NULL;
        Node* first = NULL;
        Node* last = NULL;
        while(curr || !s.empty()) {
            while(curr)  {
                s.push(curr);
                curr = curr->left;
            }

            //curr is null now
            curr = s.top();
            s.pop();

            if (!first) {
                first = curr;
            }

            //linked list assignments
            if (prevPopped) {
                prevPopped->right = curr;
                curr->left = prevPopped;
            }
            prevPopped = curr;

            if (!(curr->right && !s.empty())) //just to mark the last element
            {
                last = curr;
            }
            curr = curr->right;
        }

        first->left = last;
        last->right = first;
        return first;
    }
};