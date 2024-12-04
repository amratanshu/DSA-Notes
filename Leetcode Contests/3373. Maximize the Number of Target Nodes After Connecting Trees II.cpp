3373. Maximize the Number of Target Nodes After Connecting Trees II


HINT - answer[i] = even[i]+ max(odd[1], odd[2], …, odd[m - 1])

SOLUTION WITH TLE - (only 2 cases failing) ->

class Solution {
public:
    vector<int> findTargetNodes(vector<vector<int>>& edges, int n, bool even) {
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
                if (even) {
                    if (dist%2 == 0)
                        count += qsize;
                }
                else {
                    if (dist % 2 != 0)
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

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> ans;
        int n = edges1.size();
        int m = edges2.size();
        n++;
        m++;

        vector<int> targetNodes1Even = findTargetNodes(edges1, n, true);
        vector<int> targetNodes2Odd = findTargetNodes(edges2, m, false);

        int maxi = *max_element(targetNodes2Odd.begin(), targetNodes2Odd.end());

        for (int i = 0; i < n; i++) {
            ans.push_back(maxi + targetNodes1Even[i]);
        }

        return ans;
    }
};

This was happening because we are doing BFS for every node.
So time complex is O(N * (N + M))

BEST SOLUTION ->

Use the Property of bipartite graphs ->

1. Instead of initiating a BFS from every node, perform a BFS once for each connected component.
2. During this BFS, assign a color (either 0 or 1) to each node to indicate its partition.



class Solution {
public:
    pair<vector<int>, vector<int>> computeColorCounts(vector<vector<int>>& edges, int n) {
        vector<vector<int>> graph(n, vector<int>());
        for(auto &edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n, -1);
        vector<int> sameCount(n, 0);
        vector<int> oppositeCount(n, 0);

        for(int start = 0; start < n; ++start){
            if(color[start] == -1){
                queue<int> q;
                q.push(start);
                color[start] = 0;
                int cnt0 = 1, cnt1 = 0;
                vector<int> component = {start};

                while(!q.empty()){
                    int node = q.front(); q.pop();
                    for(auto &neighbor : graph[node]){
                        if(color[neighbor] == -1){
                            color[neighbor] = 1 - color[node];
                            if(color[neighbor] == 0) cnt0++;
                            else cnt1++;
                            q.push(neighbor);
                            component.push_back(neighbor);
                        }
                    }
                }

                for(auto &node_in_component : component){
                    if(color[node_in_component] == 0){
                        sameCount[node_in_component] = cnt0;
                        oppositeCount[node_in_component] = cnt1;
                    }
                    else{
                        sameCount[node_in_component] = cnt1;
                        oppositeCount[node_in_component] = cnt0;
                    }
                }
            }
        }

        return {sameCount, oppositeCount};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> ans;
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        pair<vector<int>, vector<int>> counts1 = computeColorCounts(edges1, n);
        pair<vector<int>, vector<int>> counts2 = computeColorCounts(edges2, m);

        vector<int> targetNodes1Even = counts1.first;
        vector<int> targetNodes2Odd = counts2.second;

        int maxi = 0;
        if(!targetNodes2Odd.empty()){
            maxi = *max_element(targetNodes2Odd.begin(), targetNodes2Odd.end());
        }

        for(int i = 0; i < n; ++i){
            ans.push_back(maxi + targetNodes1Even[i]);
        }

        return ans;
    }
};

