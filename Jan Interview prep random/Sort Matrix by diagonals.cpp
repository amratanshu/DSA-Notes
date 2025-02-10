https://leetcode.com/problems/sort-matrix-by-diagonals/

Just do what is said

Keep a temp array to keep all element ke diagonals

Choose each diagnoal ka starting point.

class Solution {
public:
    int n, m;
    void sortByStartingPoint(int i, int j, vector<vector<int>>& grid, bool rev) {
        vector<int> temp;
        int row = i;
        int col = j;
        // now i, j is the starting point
        while (row < n && col < m) {
            temp.push_back(grid[row][col]);
            row++, col++;
        }
        sort(temp.begin(), temp.end());
        if (rev) reverse(temp.begin(), temp.end());

        // now lets replace
        row = i;
        col = j;
        int k = 0; // sorted array pointer
        while (row < n && col < m) {
            grid[row][col] = temp[k];
            k++;
            row++, col++;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        // first column - starting points of diagonals
        for (int i = 0; i < n; i++) {
            sortByStartingPoint(i, 0, grid, 1);
        }

        // first row - starting points of diagonals
        for (int j = 1; j < m; j++) {
            sortByStartingPoint(0, j, grid, 0);
        }

        return grid;
    }
};