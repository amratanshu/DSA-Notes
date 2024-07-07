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


Level order will become difficult in this and even the deserialize will be very very hectic !!

------------------------------------------------------------------------------------------------------------

(Better solution is given below thi ->)
TEDIOUS BAD SOLUTION ->

My Partial solution code to this problem - 

Issue with this - the serialization is incorrect for trees like ->
[1,2,3,null,null,4,5,6,7]

The serialized string for this tree is coming out - 1$2$3$N$N$4$5$6$7$N$N$N$N$N$N

This is wrong because - we are missing the first two NULLS in the last level

So the serialization method needs to be corrected here!



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
        TreeNode* dummy = new TreeNode(-100000);
        // int level = 1;
        while (!q.empty()) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                TreeNode* fr = q.front();
                if (fr != dummy) //this is the dummy node, dont push anything for this node
                {   if (fr->left) q.push(fr->left);
                    else q.push(dummy);
                    if (fr->right) q.push(fr->right);
                    else q.push(dummy);
                }
                if (ans != "")
                    ans.append("$"); //separator
                if (fr != dummy) {
                    ans.append(to_string(fr->val));
                }
                else { 
                    ans.append("N");
                }
                q.pop();
            }

            // level = level * 2;
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return NULL;
        int i = 0;

        // create the array of strings - ["1", "2", "N"...]
        cout<<data<<endl;
        vector<string> levelOrder;
        levelOrder.push_back("");
        for (int i=0;i<data.length();i++) {
            if (data[i] == '$') {
                levelOrder.push_back("");
            }
            else if (data[i] == 'N') {
                levelOrder[levelOrder.size()-1].append("N");
            }
            else {
                levelOrder[levelOrder.size() - 1] += data[i];
            }
        }

        //lets create the tree using the array now
        for(int i=0;i<levelOrder.size();i++) {
            cout<<levelOrder[i]<<endl;
        }
        TreeNode* root = populateTree(levelOrder, 0);
        return root;
    }

    TreeNode* populateTree(vector<string> levelOrder, int i) {
        if (i > levelOrder.size() - 1) return NULL; //out of bounds
        if (levelOrder[i] == "N") return NULL;
        TreeNode* root = new TreeNode(stoi(levelOrder[i]));
        root->left = populateTree(levelOrder, 2*i + 1);
        root->right = populateTree(levelOrder, 2*i + 2);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


BETTER SOLUTION - using a recursive serialization !

This guy explains nicely !
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/solutions/608304/c-solution-using-queue-and-preorder-traversal



