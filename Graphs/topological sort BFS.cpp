KAHNS ALGORITHM

TOPO SORT - Can only be done on DAGs - Directed Acyclic Graphs

Means => Linear ordering of vertices such that if there is an edge between u and v, u appears before v in the ordering

Rule of thumb - we'll always use a Queue with BFS and Recursion with DFS

We'll use an Array here : InDegree for each edge - number of incoming edges to a node


Jiski indegree sabse kum hogi - usko sabse pehle place kar sakte hain 

if A has no edge coming towards it - inDegree = 0 - Then in the TOPO ORDER - we can have it sabse pehle obv

A se edges nikklengi bahar ki taraf !!

Some node will always be there with an indegree of 0 ! Because this is a D A G.

1. Insert all nodes with inDegree 0 in Queue
2. Take out from this queue 
3. kind of remove the edges from this node. If we do that - then adj[node] me jitne nodes honge - unki inDegree decrease hogi by one 
4. Again add all the 0 indegree nodes to the queue and repeat the process


vecetor<int> topoSort(int V, vector<int> adj[]) {
    int indegree[V] = {0};
    for (int i=0; i<V; i++)
    {
        //create indegree array easy
    }

    queue<int> q;

    for (int i=0; ...) {
        if (indegree[i] ==0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front;

        q.pop();
        topo.push_back(node);
        //node is in topo sort
        
        
        //so pls remove it from the indegree


        for (auto it: adj[node]) {
            indegree[it] --; //decrease indegree (removing edges jahan se we were coming to NODE)
            if (indegree[it] == 0) q.push(it);
        }
        
    }
    return topo;
}




SC - O(n) - queue is taking this space
TC - O(V + E)  --- every edge is being considered once. not 2E beceause directed graph tha. Undirected me double sided edges hoti hain toh 2E.
