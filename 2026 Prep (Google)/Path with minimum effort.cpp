https://leetcode.com/problems/path-with-minimum-effort/description/

Actually a HARD question (if u look at the hints on Leetcode - they have binary search and what not)

1. Normal BFS cannot work - because it will just consider one path (we can move level wise) and mark it visited.
Unless we reset the visited array for some node - we cannot revisit it again
Here - order of iterating matters. So cant use BFS

2. naive bfs cannot really deal with edge weights. And here - we technically have edge weights.

So lets do dijkstra algorithm here.

Notice how the condition of Dijksta Changes - so that we find out the maximum jump so far in this route


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        // dont need to store parent array which is used to tell the actual path!

        // pq.push({minimumEffort, node})
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            auto itr = pq.top();
            pq.pop();

            pair<int, int> node = itr.second;
            int effort = itr.first;

            //go in all possible directions
            for(auto dir: directions) {
                int x = node.first + dir.first;
                int y = node.second + dir.second;

                // if in bounds
                if (x < n && x >=0 && y < m && y >= 0) {
                    int newEffort = max(effort, abs(heights[x][y] - heights[node.first][node.second]));

                    if (newEffort < dist[x][y]) {
                        dist[x][y] = newEffort;
                        pq.push({newEffort, {x, y}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};