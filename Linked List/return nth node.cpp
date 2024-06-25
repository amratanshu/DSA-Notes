The solution off the top of our head is - traverse the linked list twice - O(2n)

But we need better optimal solution for this as well--

Slow and Fast Pointer approach

Lets look at Basic 2n approach solution - coded by me

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = head;
        if (temp->next == NULL) {
            temp = NULL;
            return temp;
        }

        int count = 1;
        while (temp->next!=NULL) {
            temp = temp->next;
            count++;
        }

        cout<<count;
        //now we are at the last node; start from behind now
        count = count - n;
        temp = head;
        ListNode* prev;
        if (count == 0) //first element hi remove karna hai
            return head->next;

        while (count > 0) {
            prev = temp;
            temp = temp->next;
            count--;
        }

        prev->next = temp->next;

        return head;
    }
};


OPTIMAL--


Create a dummy node which is pointing to HEAD- 

Assign the fast pointer to the dummy

Move the fast pointer one by one

If n = 4 

Then as soon as the fast pointer has moved ahead 4 iterations -

Now start moving the slow pointer also - slow pointer ko bhi dummy node assign kar do

So slow pointer will always stay 4 steps behind the fast pointer now

Easy solution - just do it on paper once.



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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* start = new ListNode();
        start->next = head;

        ListNode* fast = start;
        ListNode* slow = start;

        for (int i=0;i<n;i++) {
            fast = fast->next;
        }

        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return start->next;
    }
};

This solution is O(N) time complex and O(1) space complex;

