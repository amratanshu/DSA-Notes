My solution - easy concept

1. Iterate till either of the linked lists end
2. Store in both LLs - the sum of the two numbers
3. Maintain a carry properly
4. When one list ends - iterate over the other one maintaing carry and a sum and return the head of this particular list.



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = new ListNode();
        ListNode* ptr2 = new ListNode();

        ptr1->next = l1;
        ptr2->next = l2;

        int carry = 0;
        while (ptr1 != NULL && ptr2 != NULL) {
            int sum = ptr1->val + ptr2->val + carry;

            // sum%10 -> this is the number we want to leave her
            ptr1->val = sum % 10;
            ptr2->val = sum % 10;

            if (sum >= 10)
                carry = 1;
            else
                carry = 0;

            if (ptr1->next == NULL && ptr2->next == NULL) {
                if (carry == 1) {
                    ptr1->next = new ListNode(1);
                    ptr1->next->next = NULL;
                    return l1;
                }
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        // whichever is not null - iterate over it
        ListNode* temp;

        if (ptr1 == NULL)
            temp = ptr2;
        else
            temp = ptr1;

        while (temp != NULL) {
            int sum = temp->val + carry;
            temp->val = sum % 10;

            if (sum >= 10)
                carry = 1;
            else
                carry = 0;
            // last case - if we have a leading 1 in the end
            if (temp->next == NULL && carry == 1) {
                temp->next = new ListNode(1);
                temp->next->next = NULL;
                break;
            }
            temp = temp->next;
        }

        if (ptr1 == NULL)
            return l2;
        else
            return l1;
    }
};