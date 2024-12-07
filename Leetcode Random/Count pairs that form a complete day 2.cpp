https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/description/

Cant do brute force here - because constraints are large.

Dont make a map of hours[i].

Rather make a map of remainders only ! - 24 remainders possible. So O(1)

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> m; //map of remainders
        long long count = 0;
        for (auto h: hours) {
            count += m[(24 - h%24)%24];
            m[h%24]++;
        }
        return count;
    }
};