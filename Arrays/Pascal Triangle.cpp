https://leetcode.com/problems/pascals-triangle/submissions/1233228078/

My own basic solution -

class Solution {
public:
vector<vector<int>> generate(int numRows) {

        vector<vector<int>> pascal;

        vector<int> firstRow;
        firstRow.push_back(1);

        pascal.push_back(firstRow);

        vector<int> rowPrev;
        rowPrev = firstRow;
        for (int i=1; i<numRows; i++) {
            vector<int> row(i+1);
            row[0] = 1;
            row[i] = 1;

            for(int j=1;j<i;j++) {
                row[j] = rowPrev[j-1] + rowPrev[j];
            }

            pascal.push_back(row);
            rowPrev = row;
        }

        return pascal;
    }

};


Striver - 

Solve using nCr formula from PnC

r-1 "C" c-1 -- combinatorics



https://www.youtube.com/watch?v=bR7mQgwQ_o8&ab_channel=takeUforward