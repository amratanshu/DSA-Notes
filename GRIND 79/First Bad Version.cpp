https://leetcode.com/problems/first-bad-version/description/

Simple binary search

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // Binary Search
        int start = 1;
        int end = n;
        int mid;
        int ans;
        while (start <= end) {
            mid = start + (end - start) / 2;
            int res = isBadVersion(mid);
            if (res) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};