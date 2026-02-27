https://leetcode.com/problems/01-matrix/description/

First intuition -> for every cell - ans would be min(all adjacent corners) + 1

This is a BFS problem

Approach - start multiple BFS algos from all the present 0s in the grid.
Keep a visited grid

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, -1));

        queue<pair<int, int>> q;


        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] == 0) {
                    vis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};

        while(!q.empty()) {
            pair<int, int> fr = q.front();
            q.pop();

            //doing bfs here - visiting all adjacent and marking them here if not already marked
            for(auto &d: dir) {
                int x = fr.first + d[0];
                int y = fr.second + d[1];

                //in bounds and not visited yet
                if (x < m && x >=0 && y<n && y>=0 && vis[x][y] == -1) {
                    q.push({x,y});
                    vis[x][y] = vis[fr.first][fr.second] + 1;
                }
            }
            
        }
        return vis;
    }
};