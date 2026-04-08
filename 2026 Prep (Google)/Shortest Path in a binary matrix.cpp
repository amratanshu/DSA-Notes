https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

we need to do BFS (level wise shortest distance) because this is SHORTEST PATH in Undirected Acyclic Graph
If it was directed acyclic - Topological Sort wala method use karte (check out striver resources in that order)
If it was cyclic - dijkstra algo

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0) return -1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

        queue<pair<int, int>> q;
        dist[0][0] = 1;
        q.push({0, 0}); //origin pushed

        while(!q.empty()) {
            pair<int, int> fr = q.front();
            q.pop();

            //adjacent ones checking in all directions
            for (auto dir: directions) {
                int x = fr.first + dir.first;
                int y = fr.second + dir.second;

                //if in bounds AND grid is ZERO there (can travel on it)
                if (x < n && x >= 0 && y < n && y >= 0 && grid[x][y] == 0) {
                    //checking the distance stored vs distance required to reach from current
                    if (1 + dist[fr.first][fr.second] < dist[x][y]) {
                        dist[x][y] = 1 + dist[fr.first][fr.second];
                        q.push({x, y});
                    }
                }
            }
        }

        if (dist[n-1][n-1] == INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};