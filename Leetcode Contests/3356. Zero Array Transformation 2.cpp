https://leetcode.com/problems/zero-array-transformation-ii/

HINT - Binary Search and Segment Tree concepts together.

Check the comments - it will make sense!

DO zero array tranformation 1 to understand this question.

Remember what the RANGE UPDATE concept is to be efficient!!

class Solution {
public:
    bool isValidK(vector<int>& nums, vector<vector<int>> & queries, int k) {
        //process the first k queries in that order and find the strenght of that index!

        //following diff array and range update concept to find what is the strength of each index
        //(each index can decrease the value by how much)

        int n = nums.size();
        vector<int> diff(n, 0);

        for(int i=0;i<k;i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diff[l] += val;
            if (r + 1 < n) {
                diff[r+1] -= val;
            }
        }

        //now find the prefix sum of diff array to find out the strenght of each index
        for (int i=1; i<diff.size();i++) {
            diff[i] = diff[i] + diff[i-1];
        }

        //now check if each index has the strenght to make that element zero
        for (int i=0; i<n; i++) {
            if (diff[i] < nums[i]) return false;
        }
        return true;

    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        int low = 0;
        int high = queries.size();
        int ans = -1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if (isValidK(nums, queries, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};