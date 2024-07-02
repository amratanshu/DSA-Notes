
We have to imagine a full complete tree - even with NULL nodes

We need indexes for each node basically.

For any curr with index i

left child - 2*i index
right child - 2*i + 1 index

For 0 based indexing 
Left - 2 * (i) + 1
Right - 2 * (i) + 2

right - left + 1 is the width. Keep checking max while traversing it level wise

------------------------------------------------------------------------------------------------------------
NOTE - multiplying by 2 can cause an overflow so handle it!

HOW TO HANDLE OVERFLOW??
If we give the root index 1 and start with 2 - 3 - 4 - 5 - 6 ...

At a very lower level - the indexes can too big - cant even fit in double or something

SO - we need to use indexes relative to each level.

Level 0  - index 1
Level 1 - 1 2
Level 2 - 1 2 3 4
Level 3 - 1 2 3 4 5 6 7 8

By this logic - if u see the pattern 

left child - 2*i-1 index
right child - 2*i  index

Even then - overflow can happen when multiplying with 2 - so when going through
and assigning indexes to a level (pushing to the queue) - 

SO before comparison - dont just directly compare the indexes
Just subtract all indexes from the parent child - when we are pushing its children to the queue (and popping parent)

RE UNDERSTAND THIS - a little confusing as to why this is different than simple 1 based indexing.

But if we subtract and store the indexes - how will they be the correct indexes??
If at a level - z is the index of the first node (left most element of that level)
the index of ith element children will be - 

Left - 2 * (i-z) + 1
Right - 2 * (i-z) + 2

Oh, Striver has done the same thing - https://www.youtube.com/watch?v=ZbybYvcVLks&ab_channel=takeUforward

See the vid to visualize
------------------------------------------------------------------------------------------------------------

CODE ->

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // iterative solution
        if (!root) {
            return 0;
        }
        queue<pair<TreeNode*, long long>> q; //TreeNode to index of the node
        q.push({root, 0});
        long long ans = 0;
        while (!q.empty()) {
            int n = q.size();

            //handling overflow - subtract both with the index value of the parent - so that it doesnt get too big - 
            //we just need the difference in the indexes
            long long minus = q.front().second;

            long long first = 0;
            long long last = 0;
            
            
            //the queue will contain elements only from the same level (==same vertical height)
            for(int i=0; i<n; i++) {
                auto it = q.front();

                //0th is the left most in this level
                if (i == 0) {
                    first = q.front().second - minus;
                }

                //n-1th is the right most in this level
                if (i == n-1) {
                    last = q.front().second - minus;
                }

                q.pop();

                if (it.first->left) {
                    q.push({it.first->left, 2*(it.second-minus)+1});
                }

                if (it.first->right) {
                    q.push({it.first->right, 2*(it.second-minus)+2});
                }
            }

            ans = max(ans, last - first + 1);
        }
        cout<<ans;
        return ans;
    }
};


