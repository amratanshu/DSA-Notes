https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

My code below
recursive solution - uses simple concept of column and row (horizontal and vertical levels)
time - 
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