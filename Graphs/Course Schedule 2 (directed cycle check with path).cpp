https://leetcode.com/problems/course-schedule-ii/

Just track the path - in some variable !

Baaki solution is exactly that of dfs cycle check

But see how you are defining your edges in the graph (is it from Pre req to course or course to pre req)

This will define whether u want reverse of path or the path 

In my solution ->
//graph edge - PREREQ COURSE --> COURSE (not the other way round!)

This uses DFS topological sort only!!

Can even be done using BFS topological

Here - 
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
        ans.push_back(src);
        dfsVisited[src] = 0;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        //graph edge - PREREQ COURSE --> COURSE (not the other way round!)
        for (int i = 0; i < prerequisites.size(); i++) {
            int c1 = prerequisites[i][1];
            int c2 = prerequisites[i][0]; 
            adj[c1].push_back(c2);
        }

        vector<int>dfsVisited(numCourses, 0);
        vector<int> vis(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, dfsVisited)) {
                    return {}; 
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};