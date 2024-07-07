https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

Lot of methods

1. keep inorder + $ + postorder in the string
because inorder + postorder or inorder + preorder can uniquely identify a tree - basically any 2 can uniquely identify

2. do how LC does it - write it level wise - and keep "N" for NULLS

3. Saw a comment which said - if all the nodes null children are also marked with something (X or N or whatever) 
Then pre order of a tree is unique

Just the pre order is unique if nulls are market.

so - even for leaf nodes - mark them explicitly as X and it will be a unique string for this tree

------------------------------------------------------------------------------------------------------------

Lets attempt how leetcode does it - using level order traversal with marking NULLs

basic LO Traversal is easy

but here - the problem is - where will we stop in the queue wala loop (when to put and not put NULLS) ....

To know this - maybe we should find out the Height of the tree first and then do a level order and put
Nulls in all the empty places


Level order will become difficult in this and even the deserialize will be very very hectic !!

------------------------------------------------------------------------------------------------------------

(Better solution is given below thi ->)
TEDIOUS BAD SOLUTION ->

My solved solution for this problem -
[1,2,3,null,null,4,5,6,7]
The serialized string for this tree is coming out - 1$2$3$N$N$4$5$6$7$N$N$N$N$N$N

Now traverse this string - separate out the sub strings and form the tree using a queue and level order traversal (reverse)

ALTHOUGH -

This solution is ACCEPTED but giving Exceeded time limit !

Striver has written almost the same logic but he has used things like getline() in CS to read and break down the string

That is much more optimal 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* fr = q.front();
            q.pop();
            if (fr == NULL) {
                ans.append("N$");
            }
            else {
                q.push(fr->left);
                q.push(fr->right);
                ans.append(to_string(fr->val) + '$');
            }
        }
        //remove the extra $ from behind
        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return NULL;
        int i = 0;

        // create the array of strings - ["1", "2", "N"...]
        cout << data << endl;
        vector<string> levelOrder;
        levelOrder.push_back("");
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == '$') {
                levelOrder.push_back("");
            } else if (data[i] == 'N') {
                levelOrder[levelOrder.size() - 1].append("N");
            } else {
                levelOrder[levelOrder.size() - 1] += data[i];
            }
        }

        // lets create the tree using the array now
        for (int i = 0; i < levelOrder.size(); i++) {
            cout << levelOrder[i] << endl;
        }
        TreeNode* root = populateTree(levelOrder);
        return root;
    }

    TreeNode* populateTree(vector<string> levelOrder) {
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(levelOrder[0]));
        q.push(root);
        int itr = 1;
        while(!q.empty() && itr < levelOrder.size()) {
            TreeNode* fr = q.front();
            q.pop();
            if (levelOrder[itr] != "N") {
                fr->left = new TreeNode(stoi(levelOrder[itr]));
                q.push(fr->left);
            }
            itr++;
            if (levelOrder[itr] != "N") {
                fr->right = new TreeNode(stoi(levelOrder[itr]));
                q.push(fr->right);
            }
            itr++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


BETTER SOLUTION - using a recursive serialization !
This guy explains nicely !
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/solutions/608304/c-solution-using-queue-and-preorder-traversal


On the other hand - 
Striver did it exactly like I was doing !

His solution is pasted as a png !


