https://leetcode.com/problems/meeting-rooms/description/

Easy af

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if (n == 0) return true;
        int end = intervals[0][1];
        for(int i=1;i<n;i++) {
            if (intervals[i][0] < end) {
                return false;
            }
            else end = intervals[i][1];
        }
        return true;
    }
};