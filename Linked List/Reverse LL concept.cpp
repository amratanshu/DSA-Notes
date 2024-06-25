When you have to reverse a linked list --
always use this pseudo code

See striver video on reverse LL in K groups to understand more !


ListNode* dummy = new ListNode(0);
dummy->next = head;

ListNode* curr = dummy, *nex = dummy, *pre = dummy;

curr = pre->next;
nex = curr->next;

How many nodes u want to reverse is K ->
for (int i=1; i<k;i++) {
    curr->next = nex->next;
    nex->next = pre->next;
    pre->next = nex;
    nex = curr->next;
}