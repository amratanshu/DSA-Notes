https://leetcode.com/problems/find-eventual-safe-states/description/

Simple Graph cycle detection Problem!

First intuition - if there is a path starting from a node which is not reaching a terminal node
(that means path ghum raha hai between nodes) and given that there are only finite number of nodes - 
means a cycle exists!

So this question turns out to be - checking if a cycle exists starting from a particular node - 
which can be done using dfs directed graph - keep two arrays vis and dfs vis!



class Solution {
public:
    vector<int> ans;
    bool dfs(int src, vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfsVisited) {
        vis[src] = 1;
        dfsVisited[src] = 1;
        for (auto adjNode : adj[src]) {
            if (!vis[adjNode]) {
                if (dfs(adjNode, adj, vis, dfsVisited))
                    return true;
            } else {
                if (dfsVisited[adjNode])
                    return true;
            }
        }
        dfsVisited[src] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;

        vector<int> vis(n, 0);
        vector<int> dfsvisited(n, 0);

        for (int i=0; i<n; i++) {
            if (dfs(i, graph, vis, dfsvisited) == false) { //safe node
                ans.push_back(i);
            }
        }
        return ans;

    }
};