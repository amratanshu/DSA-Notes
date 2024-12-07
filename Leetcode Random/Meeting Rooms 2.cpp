https://leetcode.com/problems/meeting-rooms-ii/description/

basic . 
just keep track of every new room and its End Time;

O(NLogN) because of sorting.
O(N) space - in fact we can just store the room with the earliest TIME (min Greedy) and use it. This is a O(1) space soln

class Solution {
public:
    bool isValid(int start, vector<int> roomEndTimes) {
        //check if there is an end time in m less than the start time
        for (auto i: roomEndTimes) {
            if (i <= start) return true;
        }
        return false;
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int n = intervals.size();
        if (n == 0 || n == 1) return n;

        vector<int> roomEndTimes;
        for(int i=0;i<n;i++) {
            if (!isValid(intervals[i][0], roomEndTimes)) {
                //there is an overlap
                count++;
                roomEndTimes.push_back(intervals[i][1]);
            }
            else {
                //find a room where the 
                for (int j=0; j<roomEndTimes.size(); j++) {
                    if (roomEndTimes[j] <= intervals[i][0]) {
                        roomEndTimes[j] = intervals[i][1];
                        break;
                    }
                }
            }
        }
        return count;

    }
};