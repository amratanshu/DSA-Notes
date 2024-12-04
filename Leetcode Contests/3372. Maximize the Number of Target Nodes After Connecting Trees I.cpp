3372. Maximize the Number of Target Nodes After Connecting Trees I

See hints on leetcode.com - good question with basic implementation of graph traversal

class Solution {
public:
    vector<int> findTargetNodes(vector<vector<int>>& edges, int k, int n) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> targetNodes(n, 0);
        for (int start = 0; start < n; start++) {
            int count = 0;
            int dist = 0;
            vector<bool> visited(n, false);
            queue<int> q;
            
            q.push(start);
            visited[start] = true;

            while (!q.empty()) {
                int qsize = q.size();
                if (dist <= k) {
                    count += qsize;
                }
                for (int i = 0; i < qsize; i++) {
                    int node = q.front();
                    q.pop();
                    for (int neighbor : graph[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                dist++;
            }
            targetNodes[start] = count;
        }

        return targetNodes;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int> ans;
        int n = INT_MIN, m = INT_MIN;

        for (auto& edge : edges1) {
            n = max(n, max(edge[0], edge[1]));
        }
        for (auto& edge : edges2) {
            m = max(m, max(edge[0], edge[1]));
        }

        n++;
        m++;

        vector<int> targetNodes1 = findTargetNodes(edges1, k, n);
        vector<int> targetNodes2 = findTargetNodes(edges2, k - 1, m);

        int maxi = *max_element(targetNodes2.begin(), targetNodes2.end());

        for (int i = 0; i < n; i++) {
            ans.push_back(maxi + targetNodes1[i]);
        }

        return ans;
    }
};