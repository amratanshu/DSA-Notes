https://leetcode.com/problems/count-pairs-that-form-a-complete-day-i/description/

Easy brute force

class Solution {
public:
    int countCompleteDayPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if ((nums[i] + nums[j]) % 24 == 0) count++;
            }
        }
        return count;
    }
};