Detect A cycle in a Directed Graph using DFS: approach for undirected will not work here. But we'll do something similar only ->

Rule of thumb - we'll always use a Queue with BFS and Recursion with DFS

concept of 2 visited arrays !
visited and dfsVisited

dfs (node, parentNode)

Concept: we start DFS on somewhere and if we reach any node which has already been visited in the past
then we can say that it has a cycle

This is also done in a (node, parent node) way only


visitedArray - all marked 0 initially
adjList 


First call - DFS(1, parent) 

DFS(1, -1) 

bool dfs(int node, int parent, vector<int> vis[], vector<int> adj[]) {
    vis[node] = 1;
    for (auto adjNode: adj[node]) {
        if (!vis[adjNode]) {
            if (dfs(adjNode, node, vis, adj) == true)
                return true;
        }
        else if(adjNode != parent) return true;
    }
    return false;
}

IN CASE OF UNCONNECTED GRAPH ->

In case of graph which has multiple connected components - call this method from each node which is unvisited..?

for (i=1 -> 9)
{
    if (!vis[i])
        if (dfs(i) == true)
            return true;
}
return false;


TC - O(n + 2E) + O(n) 

SC - O(n) + O(n) ~ O(n)