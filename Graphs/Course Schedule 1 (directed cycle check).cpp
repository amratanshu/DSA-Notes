https://leetcode.com/problems/course-schedule/

recursive DFS traversal in directed graph = thats it

class Solution {
public:
    bool dfs(int src, vector<vector<int>> &adj, vector<int> &vis, vector<int> &dfsVisited) {
        vis[src] = 1;
        dfsVisited[src] = 1;
        for(auto adjNode: adj[src]) {
            if (!vis[adjNode]) {
                if (dfs(adjNode, adj, vis, dfsVisited))
                    return true;
            }
            else {
                if (dfsVisited[adjNode])
                    return true;
            }
        }
        dfsVisited[src] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            int c1 = prerequisites[i][0];
            int c2 = prerequisites[i][1];
            adj[c1].push_back(c2);
        }
        vector<int>dfsVisited(numCourses, 0);
        vector<int> vis(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i])
                if (dfs(i, adj, vis, dfsVisited))
                    return false;
        }

        //if all courses are visited - return true
        return true;
    }
};