https://leetcode.com/problems/path-with-maximum-probability/description/

Dijkstra only nothing fancy

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i=0;i<edges.size();i++) {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            adj[node1].push_back({node2, succProb[i]});
            adj[node2].push_back({node1, succProb[i]});
        }
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;
        set<pair<double,int> , greater<pair<int,double>> > s;
        s.insert({1.0, start_node});
        while(!s.empty()) {
            pair<double, int> temp = *s.begin();
            int node = temp.second;
            s.erase(s.begin());
            for (auto adjN: adj[node]) {
                int adjNode = adjN.first;
                double prob2 = adjN.second;
                double product = prob[node]*prob2;
                if (product > prob[adjNode]) {
                    auto record = s.find({prob[adjNode], adjNode});
                    if (record != s.end()) //found in set, but no need of this anymore
                        s.erase(record);
                    prob[adjNode] = product;
                    s.insert({product, adjNode});
                }
            }
        }
        return prob[end_node];

    }
};