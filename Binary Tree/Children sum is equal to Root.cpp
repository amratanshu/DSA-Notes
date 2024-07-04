https://www.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent

Easy recursive solution ->

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.

    int isSumProperty(Node *root)
    {
        if (!root->left && !root->right) return 1;
        int left = 0;
        int right = 0;
        if (root->left) left = root->left->data;
        if (root->right) right = root->right->data;
        if (left + right != root->data) return 0;
        if ((root->left && isSumProperty(root->left) == 0) || 
            (root->right && isSumProperty(root->right) == 0)) return 0;
        return 1;
    }
};