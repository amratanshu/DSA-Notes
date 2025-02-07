https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

My code below
recursive solution - uses simple concept of column and row (horizontal and vertical levels)

time - O(NLogN) - How? -> recursive traversal O(N) + insertion into map O(1)* N + sorting each col (worst case 
all nodes are in the same vertical column - O(NLogN))

space - O(N)

Striver solution below this ->



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
    
    map<int, vector<vector<int>>> m; //actually holding pairs.

    void addToTraverse(int column, int row, TreeNode* node) {
        vector<int> temp;
        temp.push_back(row);
        temp.push_back(node->val);
        if (m.find(column) == m.end()) { //not found
            vector<vector<int>> v;
            v.push_back(temp);
            m[column] = v;
        }
        else {
            m[column].push_back(temp);
        }

        if (node->right)
            addToTraverse(column + 1, row + 1, node->right);

        if (node->left)
            addToTraverse(column - 1, row + 1, node->left);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> a;
        if (!root)
            return a;

        addToTraverse(0, 0, root);
        for (auto itr : m) {
            vector<int> temp1;
            // return itr.second;
            sort(itr.second.begin(), itr.second.end());
            for (int i=0; i<itr.second.size(); i++) {
                temp1.push_back(itr.second[i][1]);
            }

            a.push_back(temp1);
            
        }
        return a;
    }
};


But still - it can be done iteratively as well - 
1. using a Queue (node, vertical, horizontal level)
2. Using a map<node, map<node, multiset<node>>> 

why using a multiset? question stated that it can have same values

if u use set - there can be a value 9 at position 0,1 and also at position 1,1 

Check screenshot


ITERATIVE ->

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;
        map<int, vector<int>> ans_mp;
        q.push({root, 0});
        
        while (!q.empty()) {
            int n = q.size();
            map<int, vector<int>> mp;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front().first;
                int line = q.front().second;
                
                mp[line].push_back(curr->val);
                if (curr->left) q.push({curr->left, line - 1});
                if (curr->right) q.push({curr->right, line + 1});
                q.pop();
            }
            for (auto& it : mp) {
                sort(it.second.begin(), it.second.end());
                ans_mp[it.first].insert(ans_mp[it.first].end(), it.second.begin(), it.second.end());
            }
        }
        
        for (auto& x : ans_mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};