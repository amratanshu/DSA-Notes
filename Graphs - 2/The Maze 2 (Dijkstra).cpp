https://leetcode.com/problems/the-maze-ii/description/

Basic dijkstra - just keep travelling until you hit a wall and then start inserting into the set from that
cell.

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze[destination[0]][destination[1]]) return -1;

        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dist[start[0]][start[1]] = 0;
        set<pair<int, pair<int, int>>> s; //distance, x index, y index
        s.insert({0, {start[0], start[1]}});
        while(!s.empty()) {
            int d1 = (*s.begin()).first;
            int i = (*s.begin()).second.first;
            int j = (*s.begin()).second.second;
            s.erase(s.begin());
            vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            for (auto dir : directions) {
                int x = i;
                int y = j;
                int travel = 0;
                //out of bounds check
                while (x + dir[0] >= 0 && x + dir[0] < m && y + dir[1] >= 0 && y + dir[1] < n && maze[x + dir[0]][y + dir[1]] == 0) {
                    x += dir[0];
                    y += dir[1];
                    travel ++;
                }
                vector<int> vec {x, y}; //stopped at this index
                if (d1 + travel < dist[x][y]) {
                    s.insert({d1 + travel, {x, y}});
                    dist[x][y] = d1 + travel;
                }
            }
        }

        if (dist[destination[0]][destination[1]] == INT_MAX) return -1;
        return dist[destination[0]][destination[1]];
    }
};