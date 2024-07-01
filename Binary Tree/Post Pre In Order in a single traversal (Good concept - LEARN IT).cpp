https://www.naukri.com/code360/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

https://www.youtube.com/watch?v=ySp2epYvgTE&ab_channel=takeUforward

Have a stack - which stores pair <node, num>

Push the root

Start popping and pushing the childs

While popping some rules -

if num == 1
    add this to the preorder
    increase the num by 1 i.e num ++
    if (node->left)
        push the node->left over the stack

if (num == 2) { //visiting it second time
    add this to the inorder - because an element comes at the second position in inorder (left - 1, curr - 2, right - 3)
    ++ num
    if (node ->right)
        push node->right
}
if (==3)
    add this to postorder
    done

CODE ->

                            
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to get the Preorder,
// Inorder and Postorder traversal
// Of Binary Tree in One traversal
vector<vector<int>> preInPostTraversal(Node* root) {
    // Vectors to store traversals
    vector<int> pre, in, post;

    // If the tree is empty,
    // return empty traversals
    if (root == NULL) {
        return {};
    }

    // Stack to maintain nodes
    // and their traversal state
    stack<pair<Node*, int>> st;

    // Start with the root node
    // and state 1 (preorder)
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // this is part of pre
        if (it.second == 1) {
            // Store the node's data
            // in the preorder traversal
            pre.push_back(it.first->data);
            // Move to state 2
            // (inorder) for this node
            it.second = 2;
            // Push the updated state
            // back onto the stack
            st.push(it); 

            // Push left child onto
            // the stack for processing
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }

        // this is a part of in
        else if (it.second == 2) {
            // Store the node's data
            // in the inorder traversal
            in.push_back(it.first->data);
            // Move to state 3
            // (postorder) for this node
            it.second = 3;
            // Push the updated state
            // back onto the stack
            st.push(it); 

            // Push right child onto
            // the stack for processing
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }

        // this is part of post
        else {
            // Store the node's data
            // in the postorder traversal
            post.push_back(it.first->data);
        }
    }

    // Returning the traversals
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}


