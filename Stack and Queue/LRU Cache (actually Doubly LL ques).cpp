https://www.youtube.com/watch?v=Xc4sICC8m4M&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=77&ab_channel=takeUforward

The comments in the code make it understandable

The head ke next wala is the MRU element
Tail ke just pehle wala is the LRU element

In the map - we are storing the key to the address of the Node in the LL

When put() - we update the map accordingly

Implementation of doubly linked list !

class LRUCache {
public:
    class Node {
        public: 
            int key;
        int value;
        Node *next;
        Node *prev;
        Node(int k, int v) {
            key = k;
            value = v;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> m;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) { //adds this new node just after the head
        Node* headNext = head->next;
        head->next = newNode;
        newNode->next = headNext;
        newNode->prev = head;
        headNext->prev = newNode;
    }

    void deleteNode(Node* node) {
        Node* pre = node->prev;
        Node* nex = node->next;

        pre->next = nex;
        nex->prev = pre;

        //we dont wanna delete this from memory because we want to add it again, just in front of the head node using add method
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) { //key not found
            return -1;
        }

        Node* res = m[key];
        int ans = res->value;
        //delete from wherever it is and add it just in front of the head
        m.erase(key);
        deleteNode(res);
        addNode(res);
        m[key] = head->next;
        return ans;
    }
    
    void put(int key, int value) {
        //if already found
        if (m.find(key) != m.end()) {
            //delete from wherever it is
            Node* res = m[key];
            m.erase(key);
            deleteNode(res);
        }

        if (m.size() == cap) { //delete the node previous to tail
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* res = new Node(key, value);
        addNode(res);
        m[key] = head->next;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */