Concept - 

Maintain a map of addresses - original node to copy node addresss

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        Node* temp = head;
        unordered_map<Node*, Node*> m;
        //create the main list copy copying the next pointers.
        //store the mapping in a hashmap.
        temp = head;
        Node* newHead = new Node(temp->val);
        Node* prev = newHead;
        m[temp] = prev;
        temp = temp->next;
        while(temp!=NULL) {
            Node* newNode = new Node(temp->val);
            prev->next = newNode;
            m[temp] = newNode; //<original , copy> in map

            prev = newNode;
            temp = temp->next;
        }
        prev->next = NULL; //end the new copied list


        //now assign the random pointers using the Map.

        temp = head;
        Node* temp2 = newHead;
        while(temp!=NULL) {
            if (temp->random == NULL)
                temp2->random = NULL;
            else {
                temp2->random = m[temp->random];
            }

            temp = temp->next;
            temp2 = temp2->next;
        }

        return newHead;
    }
};