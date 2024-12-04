3372. Maximize the Number of Target Nodes After Connecting Trees I


class Solution {
public:
    int findTargetNodes(vector<vector<int>>& edges, int k, int start) {
        int n = edges.size();
        map<int, set<int>> graph;

        // Build the graph
        for (auto edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        int count = 0;
        int dist = 0;
        set<int> visited;
        queue<int> q;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int qsize = q.size();
            if (dist <= k) count += qsize;
            for (int i = 0; i < qsize; i++) {
                int node = q.front();
                q.pop();
                // count++;

                // Traverse the neighbors of the current node
                for (int neighbor : graph[node]) {
                    if (visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
            dist++;
        }
        return count;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        vector<int> ans;
        int n = INT_MIN, m = INT_MIN;
        for (auto edge : edges1) {
            n = max(n, max(edge[0], edge[1]));
        }
        for (auto edge : edges2) {
            m = max(m, max(edge[0], edge[1]));
        }

        n++;
        m++;
        vector<int> targetNodes1;
        for (int i = 0; i < n; i++) {
            targetNodes1.push_back(findTargetNodes(edges1, k, i));
        }
;

        vector<int> targetNodes2;
        for (int i = 0; i < m; i++) {
            targetNodes2.push_back(findTargetNodes(edges2, k - 1, i));
        }

        for (int i = 0; i < n; i++) {

            int maxi = INT_MIN;
            for (int j = 0; j < m; j++) {
                maxi = max(targetNodes2[j], maxi);
            }

            ans.push_back(maxi + targetNodes1[i]);
        }
        return ans;
    }
};