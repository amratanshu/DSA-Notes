EASY Dijkstra

https://leetcode.com/problems/network-delay-time/

My code ->

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto triplet: times) {
            adj[triplet[0] - 1].push_back({triplet[1] - 1, triplet[2]});
        }

        vector<int> time(n, INT_MAX);
        time[k-1] = 0;
        set<pair<int,int>> s;
        s.insert({0, k-1});
        while(!s.empty()) {
            pair<int, int> temp = *s.begin();
            int node = temp.second;
            int t1 = temp.first;
            s.erase(s.begin());
            for (auto adjN: adj[node]) {
                int adjNode = adjN.first;
                int t2 = adjN.second;
                if (t1 + t2 < time[adjNode]) {
                    auto record = s.find({time[adjNode], adjNode});
                    if (record != s.end()) //found in set, but no need of this anymore
                        s.erase(record);
                    time[adjNode] = t1 + t2;
                    s.insert({t1 + t2, adjNode});
                }
            }
        }
        int ans = INT_MIN;
        for (auto t: time) {
            if (t == INT_MAX) return -1;
            ans = max(ans, t);
        }
        return ans;
    }
};