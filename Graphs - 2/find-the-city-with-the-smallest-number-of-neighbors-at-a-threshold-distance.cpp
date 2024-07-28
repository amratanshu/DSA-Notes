https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

Easy floyd warshall algo application

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int> (n, INT_MAX));

        for (int i=0;i<n;i++) {
            adj[i][i] = 0;
        }

        for (int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u][v] = w;
            adj[v][u] = w;
        }

        for (int v=0;v<n;v++) {
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                    //i to j via v
                    if (adj[i][v] == INT_MAX || adj[v][j] == INT_MAX)
                        continue;
                    adj[i][j] = min (adj[i][v] + adj[v][j], adj[i][j]);
                }
            }
        }

        //now we have the shortest distances from each node to each node
        //lets count now

        int ans;
        int minCount = INT_MAX;
        for (int i=0;i<n;i++) {
            int count = 0;
            for (int j=0;j<n;j++) {
                if (adj[i][j] <= distanceThreshold) count++;
            }
            if (count <= minCount) {
                minCount = count;
                ans = i;
            }
        }
        return ans;
    }   
};