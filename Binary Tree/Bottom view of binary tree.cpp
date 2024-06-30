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

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


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

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends