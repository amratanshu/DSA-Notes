https://leetcode.com/problems/connecting-cities-with-minimum-cost/description/

Easy prims algo

Return -1 if we cant connect all edges at all

When to return -1? if at the end - the number of visited nodes are not equal to n - that means
this is not a strongly connected MST ---.. basically mst isnt possible

CODE ->

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        //prim's MST algorithm implementation
        vector<vector<pair<int, int>>> adj(n);
        vector<bool> visited(n, false);
        for(int i=0; i<connections.size();i++) {
            int x = connections[i][0];
            int y = connections[i][1];
            int w = connections[i][2];

            adj[x-1].push_back({y-1, w});
            adj[y-1].push_back({x-1, w});
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
        if (numVisited == n) return sum;
        return -1;
    }
    
};