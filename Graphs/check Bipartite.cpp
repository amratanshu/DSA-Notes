LC LINK - https://leetcode.com/problems/is-graph-bipartite/submissions/

CONCEPT - Done using DFS - by giving set A and B alternatively between calls to nodes in adj List 
Think of the sets as colors - color A and B or 0 and 1.

If we find the same color of node and adjNode - return false ! bas itna sa concept hain

Beware of edge cases.



class Solution {
public:
    bool checkDFS(int node, vector<vector<int>> graph, vector<int> &vis, int setNumber) {
        vis[node] = setNumber;

        int alterSet;
        if (setNumber == 1)
            alterSet = 0;
        else
            alterSet = 1;
        
        for (auto adjNode: graph[node]) {
            if (vis[adjNode] == -1) {
                if (!checkDFS(adjNode, graph, vis, alterSet)) {
                    return false; //call with opposite coloring
                }
            }
            else {                
                if (vis[node] == vis[adjNode]) //same coloring
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        //graph is the adj list

        vector<int> vis(graph.size(), -1);
    
        //PAY ATTENTION - here, handle cases where adjList is empty - that simply means
        //there is one LONER node - how to handle this one ? THIS WILL HAPPEN IF THE GRAPH IS NOT CONNECTED ONE
        //so solution - do a dfs check on every node like Striver did for unconnected graphs
        
        for (int i=0; i<graph.size(); i++) {
            if (vis[i] == -1) {
                if (!checkDFS(i, graph, vis, 0))
                {
                    return false; 
                }
            }
        
        }
        return true;
    }
};


My Solution using BFS ->

class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<bool> &color) {
        queue<int> q;
        vis[node] = 1;
        q.push(node);
        while (!q.empty()) {
            int fr = q.front();
            q.pop();

            for (auto adjNode : graph[fr]) {
                if (!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push(adjNode);
                    color[adjNode] = !color[fr];
                } else {
                    if (color[adjNode] == color[fr])
                        return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); // no of nodes
        int m = graph[0].size();
        vector<int> vis(n, 0);
        vector<bool> color(n, false);
        for (int i=0;i<n;i++) {
            if (vis[i] == 0 && !graph[i].empty()) {
                if (!bfs(i, graph, vis, color))
                    return false;
            }
        }

        return true;
    }
};

