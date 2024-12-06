https://leetcode.com/problems/find-if-array-can-be-sorted/description/?envType=daily-question&envId=2024-11-06

Upon closer examination of the allowed operation (or perhaps after reading the hint! :)), 
we find that we can divide the array into segments of consecutive elements with the same number of set bits. 
Since these elements can be swapped with one another, we could sort each segment individually. 
However, we are not permitted to change the order of the segments themselves, nor can we swap elements that 
belong to different segments, as they have different numbers of set bits.

Therefore, we must verify that the segments are arranged correctly. Specifically, the maximum value of each 
segment (the one that would be the rightmost in its sorted order) must be less than or equal to the minimum 
value of the subsequent segment (the leftmost in its sorted order).

class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        
        while(n > 0) {
            if (n & 1) count++;
            n = n >> 1;
        }
        return count;
    }

    bool canSortArray(vector<int>& nums) {
        if (nums.size() <= 1) return true;

        int maxSeg = nums[0];
        int minSeg = nums[0];

        int maxOfPrevSegment = INT_MIN;
        int setBits = countSetBits(nums[0]);
        for(int i=1;i<nums.size();i++) {
            int newSetBits = countSetBits(nums[i]);
            if (newSetBits == setBits) { //same segment - no change in this window
                maxSeg = max(maxSeg, nums[i]);
                minSeg = min(minSeg, nums[i]);
            }

            else { //segment change
                if (maxOfPrevSegment > minSeg) return false;
                setBits = newSetBits;
                maxOfPrevSegment = maxSeg;
                maxSeg = nums[i];
                minSeg = nums[i];
            }
        }
        if (minSeg < maxOfPrevSegment) return false;
        return true;
    }
};