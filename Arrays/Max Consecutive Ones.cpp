https://leetcode.com/problems/max-consecutive-ones/

Easy to understand by looking at the code only

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecutive = 0;
        int consecutive = 0;

        for (int i=0;i<nums.size();i++) {
            if (nums[i] == 1) {
                consecutive ++;
                maxConsecutive = max(maxConsecutive, consecutive);
            }
            else {
                consecutive = 0;
            }
        }

        return maxConsecutive;
    }
};