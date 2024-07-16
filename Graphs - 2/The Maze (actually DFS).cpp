https://leetcode.com/problems/the-maze/ - LC premium question

class Solution {
public:
    bool dfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, vector<vector<bool>>& visited) {
        int i = start[0];
        int j = start[1];
        if (i == destination[0] && j == destination[1])
            return true;

        if (visited[i][j])
            return false;

        visited[i][j] = true;
        int m = maze.size();
        int n = maze[0].size();

        // Define the directions for up, down, left, right
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto dir : directions) {
            int x = i;
            int y = j;

            //move in directions until you hit a wall
            while (x + dir[0] >= 0 && x + dir[0] < m && y + dir[1] >= 0 &&
                   y + dir[1] < n && maze[x + dir[0]][y + dir[1]] == 0) {
                x += dir[0];
                y += dir[1];
            }
            vector<int> vec {x, y};
            // Perform DFS from the new stop position
            if (dfs(maze, vec, destination, visited))
                return true;
        }

        return false;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(maze, start, destination, visited);
    }
};