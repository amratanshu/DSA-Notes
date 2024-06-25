using BFS and Queue..

My own code -

Do a dry run - you will understand

In the bfs method - we have to remove all elements in the queue which are present right now ..
and then add their adjacents to the queue (which will be removed in the next recursion)

hence i am not removing untill queue is full

i am removing q.size() elements every time

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // do a BFS on this

        int counter = -1;
        // maintain a queue with all the rotten oranges
        queue<pair<int, int>> q;

        // make a visited array as well
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

        int freshOrangeCount = 0;
        

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    visited[i][j] = 1;
                    q.push({i, j});
                }

                if (grid[i][j] == 1)
                    freshOrangeCount ++;
            }
        }

        //if freshOrangeCount = 0 => ans = 0 because at time = 0 we are done - no need to do BFS
        if (freshOrangeCount == 0)
            return 0;

        // now do the BFS
        bfs(q, counter, grid, visited);

        //check if any remaining good orange 
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    return -1;
                }
            }
        }
        return counter;
    }

    void bfs(queue<pair<int, int>> q, int &counter, vector<vector<int>>& grid, vector < vector<int>> & visited) {
        if (q.empty()) {
            return;
        }
        counter++;
        int size = q.size();
        while (--size >= 0) {
            int i = q.front().first;
            int j = q.front().second;

            q.pop();
            // add the adjacent oranges to the queue (if they are not visited
            // yet)

            // upper adjacent
            if (i - 1 >= 0 && visited[i - 1][j] != 1 && grid[i-1][j] != 0) {
                q.push({i - 1, j});
                visited[i-1][j] = 1;
            }

            // lower adjacent
            if (i + 1 < grid.size() && visited[i + 1][j] != 1 && grid[i+1][j] != 0) {
                q.push({i + 1, j});
                visited[i+1][j] = 1;
            }

            // right adjacent
            if (j + 1 < grid[0].size() && visited[i][j + 1] != 1 && grid[i][j+1] != 0) {
                q.push({i, j + 1});
                visited[i][j+1] = 1;
            }

            // left adjacent
            if (j - 1 >= 0 && visited[i][j - 1] != 1 && grid[i][j-1] != 0) {
                q.push({i, j - 1});
                visited[i][j-1] = 1;
            }
        }
        bfs(q, counter, grid, visited);
    }
};