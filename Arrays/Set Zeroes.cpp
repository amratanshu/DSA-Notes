https://leetcode.com/problems/set-matrix-zeroes/

Keep a marker to mark which rows are supposed to be zero and which columns are supposed to be zero.
because if we start making them zero while we are traversing - we'll miss out the aage wale zero elements as well

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //create marker sets to indicate which rows and columns are marked as zero

        set<int> zrow;
        set<int> zcol;
        for (int i=0;i<matrix.size();i++) {
            for (int j=0;j<matrix[0].size();j++) {
                if (matrix[i][j] == 0) {
                    zrow.insert(i);
                    zcol.insert(j);
                }
            }
        }
        for(auto row: zrow) {
            for(int j=0;j<matrix[0].size();j++) {
                matrix[row][j] = 0;
            }
        }
        for(auto col: zcol) {
            for(int j=0;j<matrix.size();j++) {
                matrix[j][col] = 0;
            }
        }
    }
};

O(MN)time
O(M + N) space