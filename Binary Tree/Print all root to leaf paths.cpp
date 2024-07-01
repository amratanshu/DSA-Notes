https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths

RECURSION WITH BACK TRACKING - removal of that element is really necessary from temp !

My solution ->

class Solution {
  public:
 
    void solve(Node* curr, vector<int> &temp, vector<vector<int>> &ans) {
        if (!curr)
            return;
            
        if (!curr->left && !curr->right) { //this is a leaf node
            ans.push_back(temp);
            return;
        }
        
        if (curr->left) {
            temp.push_back(curr->left->data);
            solve(curr->left, temp, ans);
            temp.pop_back();
        }
        
        if (curr->right) {
            temp.push_back(curr->right->data);
            solve(curr->right, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        
        if (!root)
            return {};
            
        vector<vector<int>> ans;
        
        vector<int> temp;
        temp.push_back(root->data);
        solve(root, temp, ans);
        // sort(ans.begin(), ans.end());
        return ans;
    }
};