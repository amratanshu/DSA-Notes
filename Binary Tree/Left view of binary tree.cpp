https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

Recursive solution is easy

Maintain current level and levelsVisited 

whenever we visit a new level - print

Do left before right and we will get the left view naturally

Strivers method is mentioned in the end --

//Function to return a list containing elements of left view of the binary tree.
void solve(Node* curr, int currentLevel, int &levelsVisited, vector<int> &ans) {
    if (!curr)
        return;
        
    currentLevel++;
    if (currentLevel > levelsVisited) {
        ans.push_back(curr->data);
        levelsVisited++;
    }
    
    solve(curr->left, currentLevel, levelsVisited, ans);
    solve(curr->right, currentLevel, levelsVisited, ans);
    
}

vector<int> leftView(Node *root)
{
   // Your code here
   
    Node* curr = root;
    vector<int> ans;
    int levelsVisited = 0;
    solve(curr, 0, levelsVisited, ans);
    
    return ans;
}


STRIVER --

Same concept he uses

But he uses a data structure ds - vector.. where he stores elements when they are the first element on that level

In my solution - i was checking current level and levelsVisited

What striver does -

If (level == vector.size())
    push to vector

return vector

TIME - O(N)
SPACE - O(H)

