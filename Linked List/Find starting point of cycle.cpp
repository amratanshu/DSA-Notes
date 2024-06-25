CONCEPT ->

To find out if we have a cycle - (at least one duplicate) -> TORTOISE AND HARE - 
Fast pointer - moves 2 point
Slow pointer - moves 1 point

If they collide - we have a cycle.

*** If we want to find the point of starting of the cycle ***

Then 
Leave one pointer as it is (at the collision place)
Start the other pointer from the HEAD (2)

Now move both pointers by 1 each. (same speed.)

This way - they will collide at the point where the cycle is starting and that is our duplicate. (9)


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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow!=NULL && fast!=NULL) {
            slow = slow->next;
            fast = fast->next;
            if (fast == NULL)
                break;
            fast = fast->next;
            if (slow == fast)
                break;
        }

        if (slow == NULL || fast == NULL)
            return NULL;

        //now move both pointers by same speed;

        slow = head;

        while (slow!=fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;

    }
};

