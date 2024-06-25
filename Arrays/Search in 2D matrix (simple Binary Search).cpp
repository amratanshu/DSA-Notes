https://leetcode.com/problems/search-a-2d-matrix/submissions/1237261217/


Simple binary search along the full sorted matrix - O(m*n)
Code - 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //simple binary search as it is sorted in the complete iterative sense
        if(matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m*n - 1;

        while (left <= right) {
            int mid = (left + right)/2;

            int row = mid / n;
            int col = mid % n;

            
            if (matrix[row][col] == target) {
                return true;
            }
            if (target > matrix[row][col]) {
                left = mid + 1;
                continue;
            }
            if (target < matrix[row][col]) {
                right = mid - 1;
                continue;
            }
        }
        
        return false;
    }
};

There is a better solution to this as well - O(n) - See solutions on this question given by some people

who have found an O(n) worst case solution - we can go right or down in the search - check out that solution as well

