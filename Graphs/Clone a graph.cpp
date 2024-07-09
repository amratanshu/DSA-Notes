https://leetcode.com/problems/clone-graph/

Good question

Do a BFS or DFS traversal and keep a map of og node to newly created node - this map will also
help us know who is visited yet

And during the traversal - mark the neighbours too

Remember - Whoever is put on the queue - consider it visited once!

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return node;
        unordered_map<Node*, Node*> m;

        queue<Node*> q;
        q.push(node);

        Node* head = new Node(node->val);
        m[node] = head;
        while (!q.empty()) {
            Node* fr = q.front();
            q.pop();
            for (auto tempNode : fr->neighbors) {
                if (m.find(tempNode) == m.end()) { // not visited yet
                    m[tempNode] = new Node(tempNode->val);
                    q.push(tempNode);
                }
                m[fr]->neighbors.push_back(m[tempNode]);
            }
        }

        return head;
    }
};