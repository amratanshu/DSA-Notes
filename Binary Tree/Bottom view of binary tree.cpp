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

BUT - NON RECURSIVE is better - why?
because we have to do the logic for vertical height and horizontal both

but iteratively - we can just do level order traversal and get away with the solution

Level Order time complexity - 
ON

Space - ON - depends on the structure of the tree

Check striver 
If we want to do it non recursively - maintain a Queue - and cover each vertical line one by one
https://www.youtube.com/watch?v=0FtVY6I4pB8&ab_channel=takeUforward
See striver video for the same

first put the root in the queue as {root, 0}
Then put {rootLeft, -1} and {rootRight, 1}

Then line is done

so - pop.. this will take out {root, 0}

similary do - add to queue -  {q.top()->left, -2} and right also
then pop.

NOTE - CHECK MY TOP VIEW OF BINARY TREE CODE - implemented iterative Queue solution there.

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



Queue soln - >
vector<int> findBottomView(Node* root)
	{
		// Write your code here...
		vector<int> ans;
		if(root == NULL) return ans;
		map<int,int>mp; // col, val;
		queue<pair<Node*, int>>Q; // node, column values
		Q.push({root, 0});
		while(!Q.empty()){
			auto it = Q.front();
			Q.pop();
			Node* node = it.first;
			int col = it.second;
			mp[col] = node->data;
			if(node->left != NULL) Q.push({node->left, col-1});
			if(node->right != NULL) Q.push({node->right, col+1});
		}
		for(auto x:mp){
			ans.push_back(x.second);
		}
		return ans;
	}