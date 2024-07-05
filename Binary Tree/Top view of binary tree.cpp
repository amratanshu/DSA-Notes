https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

My iterative Solution



vector<int> topView(Node *root)
    {
        //Your code here
        //lets do it iteratively using level order traversal
        
        vector<int>ans;
        if (!root)
            return ans;
            
        queue<pair<Node*, int>> q;
        map<int, int> m;         
        q.push({root, 0});

        while(!q.empty()) {
            pair<Node*, int> popped = q.front();
            q.pop();
            //push curr->left and curr->right into the queue
            Node* temp = popped.first;
            int hd = popped.second;
            
            if (m.find(hd) == m.end()) {
                m[hd] = temp->data;
            }
            
            if (temp->left) {
                q.push({temp->left, hd-1});
            }
            
            if (temp->right) {
                q.push({temp->right, hd+1});
            }
        }
        
        for (auto i: m) {
            ans.push_back(i.second);
        }
        
        return ans;
    }