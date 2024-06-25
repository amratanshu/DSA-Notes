GOOD QUESTION - LC HARD

https://www.youtube.com/watch?v=Of0HPkk3JgI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=35&ab_channel=takeUforward

Watch video and do a dry run to totally understand it

Make configs on paper 
config 1 - where everything is pointing rn
config 2 - where u want to point everything 

And then write the conditions for the loop

https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // lets try a recursive solution for this problem

        if (head == NULL || k == 1)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy, *nex = dummy, *pre = dummy;

        int count = 0;

        while(curr->next!=NULL) {
            curr = curr->next;
            count ++;
        }

        while (count >= k) {
            curr = pre->next;
            nex = curr->next;

            for (int i=1; i<k;i++) {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            count-=k;
        }
        return dummy->next;
    }
};