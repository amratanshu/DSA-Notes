https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

My code ->

A variable MySwitch decides the pop and push to which side - and also push left or right
Modification of Level Order Traversal

Time - beats 100%

Concept -

Take a complete binary tree with 3-4 levels to understand

See that - each level ka traversal - uske last element ke children start the next level ka traversal

Also - the left and right ka order keeps switching one by one

So we have used a DEQUEUE to add and pop from boths sides - using a flag called mySwitch

Striver solution is pretty easy one - he is just using the temp and adding elements ulta aur seedha depending upon the flag

No need for a dequeue in this case.

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return {};
        }
        deque<TreeNode*> q;
        bool mySwitch = true; //switches where to pop and push, and the order of left/right pushing
        q.push_front(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                TreeNode* it;
            
                if (mySwitch) {
                    it = q.front();
                    temp.push_back(it->val);
                    q.pop_front();
                }
                else {
                    it = q.back();
                    temp.push_back(it->val);
                    q.pop_back();
                }
                TreeNode* left = it->left;
                TreeNode* right = it->right;

                if (!mySwitch) swap(left, right);
                if (mySwitch) {
                    if (left) q.push_back(left);
                    if (right) q.push_back(right);
                }
                else {
                    if (left) q.push_front(left);
                    if (right) q.push_front(right);
                }
                
            }
            mySwitch = !mySwitch;
            ans.push_back(temp);
        }
        return ans;
    }
};