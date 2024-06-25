Apply the same concept - of reversing a linked list.

Partially reverse the linked list.

Jo second remaining part hai - usko reverse karo


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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = new ListNode(0);

        if (head->next == NULL)
            return true;

        temp->next = head;
        int count = -1;
        while (temp!=NULL) {
            count ++;
            temp = temp->next;
        }

        temp = head;
        for (int i =0;i<count/2;i++) {
            temp = temp->next;
        }   

        if (count%2 != 0) {
            temp = temp->next;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = temp;
        //now start reversing the remaining elements
        ListNode* curr = dummy, *pre = dummy, *nex = dummy;
        curr = pre->next;
        nex = curr->next;
        while (nex!=NULL) {

            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;

        }

        //now the reversed linked list head is dummy->next
        ListNode* head2 = dummy->next;
        ListNode* head1 = head;
        for(int i=0;i<count/2;i++) {
            if (head1->val != head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};