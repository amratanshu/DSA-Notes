https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

We can use any shortest path algo to find the shortest path.

Then we might have to use DP to find "number of ways" with that distance

We can actually use dijkstra with DP in a way.

Dont think about DP and all - just go with your own intuition!

Maintain an array with the number of ways with that shortest time!

Important to understand WAYS ->
1. //new shortest path just found, so no of ways will be equal to no of ways to reach node
2. //if exactly the shortest time found again - this is another shortest path leading to this - so just add the ways to reach adjNode and node (a little PnC for you)

Coded this up - But this solution - works for 34/57 test cases only

Problem - INTEGER OVERFLOW!!

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto triplet: roads) {
            //bidirectional roads
            adj[triplet[0]].push_back({triplet[1], triplet[2]});
            adj[triplet[1]].push_back({triplet[0], triplet[2]});
        }

        vector<int> time(n, INT_MAX);
        vector<int> ways(n, 0);

        time[0] = 0;
        ways[0] = 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 0});

        while(!pq.empty()) {
            auto itr = pq.top();
            pq.pop();

            int currTime = itr.first;
            int node = itr.second;

            // adjacency list traverse now
            for (auto p: adj[node]) {
                int adjNode = p.first;
                int edgeTime = p.second;

                if (currTime + edgeTime < time[adjNode]) {
                    time[adjNode] = currTime + edgeTime;
                    ways[adjNode] = ways[node]; //new shortest path just found, so no of ways will be equal to no of ways to reach node

                    pq.push({time[adjNode], adjNode});
                }
                else if (currTime + edgeTime == time[adjNode]) {
                    //this is another shortest path leading to this - so just add the ways to reach adjNode and node (a little PnC for you)

                    ways[adjNode] = (ways[adjNode] + ways[node]) % 1000000007;
                }
            }
        }

        return ways[n-1] % 1000000007;
    }
};


Correct - solved for integer overflow ->

Used LONG LONG MAX and stuff for time arrays!

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Use long long for distances and times
        vector<vector<pair<int, int>>> adj(n);
        for(auto& road: roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        long long mod = 1e9 + 7;
        // dist should be long long to avoid overflow
        vector<long long> time(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        time[0] = 0;
        ways[0] = 1;
        
        // pq should store {time, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            long long currTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Optimization: if we've already found a better time for this node, skip
            if (currTime > time[node]) continue;

            for (auto& p: adj[node]) {
                int adjNode = p.first;
                int edgeTime = p.second;

                if (currTime + edgeTime < time[adjNode]) {
                    time[adjNode] = currTime + edgeTime;
                    ways[adjNode] = ways[node]; 
                    pq.push({time[adjNode], adjNode});
                }
                else if (currTime + edgeTime == time[adjNode]) {
                    // Update ways but DO NOT push to PQ again
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return (int)(ways[n-1] % mod);
    }
};