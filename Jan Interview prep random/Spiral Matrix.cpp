https://leetcode.com/problems/spiral-matrix/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-thirty-days

My solution ->

Easy to understand 

Just keep track of the directions and keep a visited array to keep track of where to TURN

O(N*M) time 
O(N*M) space

class Solution {
public:
    vector<int> ans;
    int n, m;

    void solve(int i, int j, int dir, vector<vector<int>>& matrix, vector<vector<int>>& visited) {
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] == 1) 
            return;

        visited[i][j] = 1;
        ans.push_back(matrix[i][j]);

        // Right
        if (dir == 0) {
            if (j + 1 < m && visited[i][j + 1] == 0)
                solve(i, j + 1, 0, matrix, visited);
            else
                solve(i + 1, j, 1, matrix, visited);
        }
        // Down
        else if (dir == 1) {
            if (i + 1 < n && visited[i + 1][j] == 0)
                solve(i + 1, j, 1, matrix, visited);
            else
                solve(i, j - 1, 2, matrix, visited);
        }
        // Left
        else if (dir == 2) {
            if (j - 1 >= 0 && visited[i][j - 1] == 0)
                solve(i, j - 1, 2, matrix, visited);
            else
                solve(i - 1, j, 3, matrix, visited);
        }
        // Up
        else if (dir == 3) {
            if (i - 1 >= 0 && visited[i - 1][j] == 0)
                solve(i - 1, j, 3, matrix, visited);
            else
                solve(i, j + 1, 0, matrix, visited);
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        solve(0, 0, 0, matrix, visited);
        return ans;
    }
};


Iterative solution with 4 boundaries ->

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        
        int top = 0, bottom = n - 1, left = 0, right = m - 1;

        while (top <= bottom && left <= right) {
            // Move right
            for (int j = left; j <= right; j++)
                ans.push_back(matrix[top][j]);
            top++;

            // Move down
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            if (top <= bottom) {
                // Move left
                for (int j = right; j >= left; j--)
                    ans.push_back(matrix[bottom][j]);
                bottom--;
            }

            if (left <= right) {
                // Move up
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};
