https://leetcode.com/problems/flood-fill/description/

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>> &vis, int oldVal) {
        if (vis[sr][sc] || image[sr][sc] != oldVal) return;
        image[sr][sc] = color;
        vis[sr][sc] = 1;

        if (sr + 1 < image.size()) dfs(image, sr+1, sc, color, vis, oldVal);
        if (sr - 1 >= 0) dfs(image, sr-1, sc, color, vis, oldVal);
        if (sc + 1 < image[0].size()) dfs(image, sr, sc + 1, color, vis, oldVal);
        if (sc - 1 >= 0) dfs(image, sr, sc - 1, color, vis, oldVal);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //depth first search
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        dfs(image, sr, sc, color, vis, image[sr][sc]);
        return image;
    }
};