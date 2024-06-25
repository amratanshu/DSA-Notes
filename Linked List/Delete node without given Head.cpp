https://leetcode.com/problems/delete-node-in-a-linked-list/submissions/1278414652/

we dont have access to previous nodes.

So just manipulate the values and copy the next value in the current node (which has to be deleted) one by one.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;

        while(temp->next->next != NULL) {
            temp->val = temp->next->val;
            temp = temp->next;
        }
        
        temp->val = temp->next->val;
        temp->next = NULL;
    }
};


