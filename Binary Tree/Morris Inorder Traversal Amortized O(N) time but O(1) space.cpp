https://leetcode.com/problems/binary-tree-inorder-traversal/

CONCEPT 

THREADED BINARY TREE 

Regular traversal - have O(N) time compelx and O(N) aux space usage

Morris - does not use any auxilliary extra space


--------------------------------------------------------------------------------------------------------------------------------
TIME COMPLEX
Time complex of Morris - it is Amortized O(N)

The inner while loop - which takes us to the left subtree ka rightmost element -
this takes time according to how long is that left to right to right to right tree branch
Sometimes it can have 2 ele
Somtimes 3 ele..
For the lower nodes - they will have 0 elemments to their left subtree ka right most..

So together - over all that while loop will take O(N) only (amortized)
Each instance can be different tho

U can check that by putting a print statement there and debugging

And the main loop - runs through all the nodes - so it takes O(N) as well

So it is near about O(N) + O(N) -- near about O(N) - not exactly
--------------------------------------------------------------------------------------------------------------------------------

Uses the concept of threaded binary tree


If you see the inorder traversal properly - 
will notice that we always come back to the root after we are done with the rightmost element of the left subtree

Recursion takes care of this naturally

But if we want to do it iteratively without using extra space like a stack or something

We can directly connect this rightmost of left subtree to the root.

REMEMBER - inorder - LEFT ROOT RIGHT

Process -

there can be 3 conditions when we are traversing each element (curr)

if (curr->left == NULL) {
    just print the root
    go to the right subtree
}

else {
    there can be two conditions here also

    go the left subtree's right most element

    1. if there is no thread - from the last element to our curr - CREATE a thread
        after creating a thread - 

        come back to curr
        go to left subtree (because this is pending obviously. and when it ends - it will come to the root back)

    2. if there is already a thread - from the last ele to our curr

        delete that thread to curr
        print the curr (because we are done with the left subtree completely now - this is the ROOT step in the traversal)
        move to right subtree - because we are done with LEFT and ROOT)
}


SUM UP
Self notes:
In-order Morris Traversal:
 1st case: if left is null, print current node and go right
 2nd case: before going left, make right most node on left subtree connected to current node, then go left
 3rd case: if thread is already pointed to current node, then remove the thread

Do a dry run to understand more and watch strivers video

https://www.youtube.com/watch?v=80Zug6D1_r4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=39&ab_channel=takeUforward


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
    vector<int> inorderTraversal(TreeNode* root) {
        //morris inorder traversal - threaded binary tree - rightmost of left subtree connected to root
        //no aux space - iterative soln

        TreeNode* curr = root;
        vector<int> inorder;
        while(curr) {
            if (curr->left == NULL) {
                inorder.push_back(curr->val);
                curr = curr->right;
            }

            else {
                //go to left subtree ka right most
                TreeNode* temp = curr->left;
                while(temp->right && temp->right != curr) { //second condition checks whether there is already a thread back to the curr
                    temp = temp->right;
                }

                if (temp->right == curr) { //already a thread, so we want to delete this (dont wanna disturb the og binary tree)
                    temp->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right; //left subtree and root are done - just go to right subtree now
                }
                else { //create new thread
                    temp->right = curr;
                    curr = curr->left;
                }
            }
        }

        return inorder;
    }
};