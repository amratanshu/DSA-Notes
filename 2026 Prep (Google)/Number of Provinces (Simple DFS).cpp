https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    int count = 0;
    void dfs(int i, vector<int>& vis, vector<vector<int>>& isConnected) {
        vis[i] = 1;
        int n = isConnected.size();

        for (int j = 0; j < n; j++) {
            if (i != j && isConnected[i][j] == 1 && vis[j] == 0) {
                dfs(j, vis, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // perform a dfs on this simply
        int n = isConnected.size();
        vector<int> vis(n, 0);

        // run on all nodes
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                count++;
                dfs(i, vis, isConnected);
            }
        }

        return count;
    }
};