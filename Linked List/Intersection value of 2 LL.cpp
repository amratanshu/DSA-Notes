https://leetcode.com/problems/intersection-of-two-linked-lists/


solution 1 - brute - bad - O (m*n)

Solution 2 - Node Address ko hashmap me dal do and check for it. - this is O(m+n) TC and O(n) SC

Solution 3 - mine -->
The solution is in the comments of this code.
TC - O(m+n) and SC O(1)

Solution 4 - Striver solution - Check the code in his video 


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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // traverse each list to the end
        // now u know the length 1 and length 2 and the difference in length
        // DIFF move DIFF steps on the longer list traverse both now from this
        // step and check where they intersect...

        if (headA == headB)
            return headA;
        
        ListNode* temp;
        int l1 = 0;
        int l2 = 0;

        temp = headA;
        while (temp != NULL) {
            l1++;
            temp = temp->next;
        }

        temp = headB;
        while (temp != NULL) {
            l2++;
            temp = temp->next;
        }

        int diff = abs(l1 - l2);
        ListNode* temp2;
        if (l1 > l2) {
            temp = headA;
            for (int i = 0; i < diff; i++) {
                temp = temp->next;
            }
            temp2 = headB;
        } else {
            temp = headB;
            for (int i = 0; i < diff; i++) {
                temp = temp->next;
            }
            temp2 = headA;
        }

        //now move both temps --
        while (temp != NULL && temp2 != NULL && temp != temp2) {
            temp = temp->next;
            temp2 = temp2->next;
        }
        if (temp == NULL)
            return NULL;
        if (temp2 == NULL)
            return NULL;

        return temp;
    }
};