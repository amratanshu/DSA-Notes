https://leetcode.com/problems/cheapest-flights-within-k-stops/

This can also be solved by bellman ford (as already done in another folder in this repo)

BFS with a twist (Not exactly Dijkstra)

The Twist: Sort by "Stops," not "Price"
The "Cheapest Flights Within K Stops" problem 
is actually best solved using a Simple Queue (BFS) or a Priority Queue sorted by the number of stops.

 Since each "step" in the BFS represents exactly one flight (one stop), the number of stops 
 increases linearly ($0, 1, 2...$). This means a simple queue naturally processes nodes in order of 
 increasing stops.

 class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build the Adjacency List: {to, price}
        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // Queue for BFS: {stops, {node, cost}}
        // We use a regular queue because stops increase by 1 each time (uniform weight)
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // If we have already reached the max allowed stops, 
            // we can't take any more flights from this node.
            if (stops > k) continue;

            for (auto iter : adj[node]) {
                int adjNode = iter.first;
                int edW = iter.second;

                // Optimization: Only push to queue if we find a cheaper way
                // to reach adjNode within the  allowed stops.
                if (cost + edW < dist[adjNode]) {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }

        // If the destination is unreachable within K stops, return -1
        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};