https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

Recursive solution is easy

Maintain current level and levelsVisited 

whenever we visit a new level - print

Do left before right and we will get the left view naturally

Strivers method is mentioned in the end --

//Function to return a list containing elements of left view of the binary tree.
void solve(Node* curr, int currentLevel, int &levelsVisited, vector<int> &ans) {
    if (!curr)
        return;
        
    currentLevel++;
    if (currentLevel > levelsVisited) {
        ans.push_back(curr->data);
        levelsVisited++;
    }
    
    solve(curr->left, currentLevel, levelsVisited, ans);
    solve(curr->right, currentLevel, levelsVisited, ans);
    
}

vector<int> leftView(Node *root)
{
   // Your code here
   
    Node* curr = root;
    vector<int> ans;
    int levelsVisited = 0;
    solve(curr, 0, levelsVisited, ans);
    
    return ans;
}


STRIVER --

Same concept he uses

But he uses a data structure ds - vector.. where he stores elements when they are the first element on that level

In my solution - i was checking current level and levelsVisited

What striver does -

If (level == vector.size())
    push to vector

return vector

TIME - O(N)
SPACE - O(H)



My solution with level order traversal ->

RIGHT SIDE VIEW ->

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans; 
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()) {
            int qsize = q.size();
            
            ans.push_back(q.front()->val);
            for(int i=0; i<qsize; i++) {
                TreeNode* fr = q.front();
                q.pop();

                if (fr->right)
                    q.push(fr->right);
                if (fr->left)
                    q.push(fr->left);
            }
        }
        return ans;
    }
};