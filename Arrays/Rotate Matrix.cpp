Simple concept - 

Single rotation of a square matrix is - >
1. Transpose
2. Swap its ith column with n-ith column..

class Solution {
public:

    void transpose(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                swap(mat[i][j],mat[j][i]);
            }
        }
    }

    void swapColumns(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int j=0;j<n/2;j++) {
            //jth column from start and end being swapped

            for (int i=0;i<n;i++) {
                swap(mat[i][j], mat[i][n-1-j]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        
        transpose(matrix);
        swapColumns(matrix);
    }
};