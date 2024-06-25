The logic is all mentioned properly in the comments

If you want to know more - https://leetcode.com/problems/single-element-in-a-sorted-array/solutions/3212178/day-52-binary-search-easiest-beginner-friendly-sol


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size()-1;


        while (low < high) {

            int mid = low + (high - low)/2;

            //always fine the mid which is even. so that mid ke right me there are even numbers
            //by this logic - if mid ke right wala is a different ele - we know ANS is in the right window
            //this is because mid ke right wale window me - there are even numbers now. so all pairs.
            //if mid is odd - decrease by 1 to make it even
            if (mid%2 != 0)
                mid --;

            //if the right element is not same as mid
            if (nums[mid+1] != nums[mid]) {
                high = mid;
            }

            else
                low = mid + 2;

        }
        return nums[low];
    }
};