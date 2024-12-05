3367. Maximize Sum of Weights after Edge Removals

COULD NOT SOLVE MYSELF.

Why not greedy?
see example in the beginning of this video to understand why greedy (just selecting min edge of violating nodes) does
not work - https://www.youtube.com/watch?v=95SGr6mSpTk

So every potential edge - remove or not remove

This looks like a DP question then - basically simple DFS where for every node -
we decide -
1. isParent edge removed or not
2. how many edges to actually remove to make it valid (K condition)

The DFS is kind of doing the sum of all weights by going through all the nodes in a recursive manner.


See this for explanation - https://www.youtube.com/watch?v=ol9-DkDnOBk&ab_channel=AmitChoraria

Understand how the sorting is taking place! that is the most imp part.

CACHE IS NOTHING BUT THE DP ARRAY

class Solution {
public:
    using ll = long long;
    vector<vector<ll>> dp;

    ll maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<vector<int>>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        dp.resize(n + 1, vector<ll>(2, -1));
        return solve(adj, 0, k, 0, 0); // adj, node, k, parent, isParentRem
    }

    ll solve(vector<vector<vector<int>>>& adj, int node, int k, int parent, int isParentRem) {
        if (dp[node][isParentRem] != -1) {
            return dp[node][isParentRem];
        }

        ll ans = 0;
        int noOfEdgesToRem = max(0, (int)adj[node].size() - isParentRem - k);
        vector<pair<ll, ll>> takeNotTakeOnChildren;
        for (auto neigh : adj[node]) {
            if (neigh[0] != parent) {
                ll take = neigh[1] + solve(adj, neigh[0], k, node, 0);
                ll notTake = solve(adj, neigh[0], k, node, 1);
                takeNotTakeOnChildren.push_back({take, notTake});
            }
        }

        sort(takeNotTakeOnChildren.begin(), takeNotTakeOnChildren.end(), [](auto lhs, auto rhs) {
            return lhs.first - lhs.second < rhs.first - rhs.second;
        });

        for (int i = 0; i < takeNotTakeOnChildren.size(); i++) {
            if (i < noOfEdgesToRem) {
                ans += takeNotTakeOnChildren[i].second;
            } else {
                ans += max(takeNotTakeOnChildren[i].first, takeNotTakeOnChildren[i].second);
            }
        }

        return dp[node][isParentRem] = ans;
    }
};
