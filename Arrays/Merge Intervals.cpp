https://leetcode.com/problems/merge-intervals/description/

My approach - 
sort the complete thing first - so we never have something like - [1,4],[0,4]

Then - maintain 2 variables
low and high to denote the current window 

If there is an over lap - do what is logical and change the high
If there is no overlap - add this curent window to the answer and move on.


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int low = intervals[0][0];
        int high = intervals[0][1];

        vector<vector<int>> ans;
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i][0] > high) {
                vector<int> temp;
                temp.push_back(low);
                temp.push_back(high);
                
                ans.push_back(temp);
                
                low = intervals[i][0];
                high = intervals[i][1];
            }

            //overlap is present
            if (intervals[i][0] <= high) {
                high = max(intervals[i][1], high);
            }
        }
        vector<int> temp;
        temp.push_back(low);
        temp.push_back(high);
        
        ans.push_back(temp);
        return ans;
    }
};