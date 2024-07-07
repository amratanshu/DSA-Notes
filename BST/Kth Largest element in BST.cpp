https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

Just the opposite of Inorder traversal

Just do RIGHT ROOT LEFT !

int kthLargest(Node* root, int k) {
        if (!root)
            return -1;

        // lets write an iterative version
        stack<Node*> s;
        s.push(root);
        int count = 0;
        Node* curr = root;
        while (curr != NULL || s.empty() == false) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->right;
            }

            // curr is NULL now
            curr = s.top();
            s.pop();

            if (++count == k) return curr->data;
            curr = curr->left;
        }

        return -1;
    }