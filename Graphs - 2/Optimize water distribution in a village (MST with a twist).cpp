https://leetcode.com/problems/optimize-water-distribution-in-a-village/description/

HINT to solve this problem->
Add a virtual node, connect it to houses with edges weighted by the costs to build wells in these houses.

Now its simple MST using Prim Kruskal


class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        //solution hint: Add a virtual node, connect it to houses with edges weighted by the costs to build wells in these houses.
        //prim's MST algorithm implementation
        vector<vector<pair<int, int>>> adj(n+1); //n + 1 tp accomodate for the extra virtual node
        vector<bool> visited(n+1, false);
        for(int i=0; i<pipes.size();i++) {
            int x = pipes[i][0];
            int y = pipes[i][1];
            int w = pipes[i][2];

            adj[x-1].push_back({y-1, w});
            adj[y-1].push_back({x-1, w});
        }

        //nth node is the virtual node
        for (int i=0;i<wells.size();i++) {
            //add an edge between ith node and virtual node - bi directional
            adj[n].push_back({i, wells[i]});
            adj[i].push_back({n, wells[i]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
        //weight, node
        pq.push({0, 0});
        int sum = 0;
        int numVisited = 0;
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int w = p.first;
            int node = p.second;
            if (visited[node]) continue;
            sum += w;
            visited[node] = true;
            numVisited ++;
            for (auto i: adj[node]) {
                int adjNode = i.first;
                int edgeW = i.second;
                if (!visited[adjNode]) {
                    pq.push({edgeW, adjNode});
                }
            }
        }
        return sum;
    }
};