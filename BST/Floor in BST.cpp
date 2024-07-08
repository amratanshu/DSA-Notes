https://www.naukri.com/code360/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTabValue=SUBMISSION



************************************************************/
int solve(TreeNode<int>* root, int X, int curr_min) {
    if (root->val == X) return X;

    if (root->val > X) {
        if (root->left) return solve(root->left, X, curr_min);
        else return curr_min;
    }
    if (root->val < X) {
        if (root->val > curr_min) {
            curr_min = root->val;
            if (root->right) return solve(root->right, X, curr_min);
            return curr_min;
        }
    }
    if (!root->left && !root->right) return curr_min;
}

int floorInBST(TreeNode<int> * root, int X)
{
    // int predDiff = INT_MAX;
    // int pred = 0;
    // solve(root, pred, X, predDiff);
    // return pred;
    if (!root) return -1;
    return solve(root, X, -1);
}