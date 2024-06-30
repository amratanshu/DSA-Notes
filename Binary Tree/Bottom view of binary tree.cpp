https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

Nice and easy concept

My solution 

Concept of horizontal distance and vertical distance

traverse recursively

We have to find our - at every horizontal level - we have to find the maximum vertical level -- that will be the answer

So we keep re writing the entry in our map if we find a max VL - 

Time - O(N)
Space - O(N) - storing a map of horizontal dist to vertical dist 

this map will store all horizontal dist values but only the maximum vertical dist values - 
so in the worst case - it will be in a fully complete binary tree - 

Last level pe kitne nodes hote hain total? -- N/2

Hence O(N)

// } Driver Code Ends
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    
    void solve(Node* curr, int HL, int VL, map<int, pair<int,int>> &m) {
        if(!curr) {
            return;
        }
        
        if (m.find(HL) == m.end()) { //this horizontal level does not exist
            m[HL] = {VL, curr->data};
        }
        else {
            if (m[HL].first <= VL) {
                m[HL] = {VL, curr->data};
            }
        }
        
        solve(curr->left, HL-1, VL+1, m);
        solve(curr->right, HL+1, VL+1, m);
    }
    
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        //MAP of horizontal level --> pair(vertical level, value)
        map<int, pair<int,int>> m;
        solve(root, 0, 0, m);
        
        vector<int> ans;
        //traverse the map
        std::map<int, pair<int,int>>::iterator itr = m.begin(); 
        
        while(itr != m.end()) {
            ans.push_back(itr->second.second);
            itr++;
        }
        return ans;
    }
};