https://leetcode.com/problems/rotate-list/

Concept - 
1. find out the actual number of rotations (k can be greater than the length of the linked list)
2. if len is 5 and we wanna do 2 actual rotations - move ahead 3 nodes and then mark this node's next to NULL. 
The node just before this node is the newHead
3. traverse the remaining nodes and point their next to the original head.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if (!k)
            return head;

        if (head == NULL)
            return head;
            
        int count = 0;
        while(temp!=NULL) {
            temp = temp->next;
            count++;
        }

        int K = k%count;
        if (K == 0) {
            return head;
        }
        temp = head;
        for(int i = 0;i<count - K-1;i++) {
            temp = temp->next;
        }
        //point this one to NULL
        ListNode * end = temp;
        temp = temp->next;
        end->next = NULL;

        //now this temp is the HEAD
        ListNode* newHead = temp;

        while(temp->next!=NULL) {
            temp = temp->next;
        }

        temp->next = head;
        return newHead;

    }
};