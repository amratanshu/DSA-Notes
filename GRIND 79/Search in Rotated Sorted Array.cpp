https://leetcode.com/problems/search-in-rotated-sorted-array/description/

Simple binary search to find out which side is actually the sorted one! and just some inqualities.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0; int high = nums.size() - 1;
        int mid;
        while(low <= high) {
            int mid = low + (high - low)/2;

            if (nums[mid] == target) return mid;
            //check which side is the sorted side

            if (nums[mid] >= nums[low]) {
                //if target is within this side
                if (nums[mid] > target && nums[low] <= target) {
                    high = mid-1;
                }
                else {
                    low = mid + 1;
                }
            }
            else { //right part is sorted
                if (nums[mid] < target && target <= nums[high]) {
                    //move to this side
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }
        return -1;
    }
};