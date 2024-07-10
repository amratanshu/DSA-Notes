Detect cycle in undirected using BFS

Rule of thumb - we'll always use a Queue with BFS and Recursion with DFS

Concept: If we start on two different paths and arrive at the same path again - then CYCLIC !

Algo: we save up the previous node where we came from - in the queue.
queue has - [node, parent node] - parent means kahan se aaye hain hum node pe.

What if the graph is not connected? u need to call detectCycle on all the unconnected small pieces of graph. How will we do that?
Attached ss for this same thing

class Solution {
public:
    bool detectCycle(int src, vector<int> adj, int vis[]) {
        vis[src] = 1;

        queue<pair<int,int>> q;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;

            q.pop();

            //go to all its adjacent nodes because this is BFS
            for (auto adjNode: adj[node]) {
                //if already visited
                if (vis[adjNode] != 1) {
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                else {
                    if (parent != adjNode)
                        return true;
                }
            }
        }

        return false;

    }
}