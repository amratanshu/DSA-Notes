class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //starting point and ending point both are variable here.
        int n = matrix.size();
        vector<int> lastRow(n,0);

        if (n==1)
            return matrix[0][0];

        int ans;
        vector<int> curr(n);
        for (int i=0; i<n; i++) {
            lastRow[i] = matrix[0][i];
        }    
        for (int i=1; i<n; i++) {
            ans = INT_MAX;
            for (int j=0;j<n;j++) {
                int add;
                if (j==0) {
                    add = min(lastRow[j], lastRow[j+1]);
                }
                else if (j==n-1) {
                    add = min(lastRow[j], lastRow[j-1]);
                }
                else {
                    add = min(min(lastRow[j], lastRow[j-1]), lastRow[j+1]);
                }
                curr[j] = matrix[i][j] + add;
                if (curr[j] < ans)
                    ans = curr[j];
            }
            lastRow = curr;
        }
        return ans;
        
    }
};