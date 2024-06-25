CONCEPT --

Store maxTillNow
Store indexToWrite - write the new unique number found here.

O(n) solution to solve it just one go.


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int maxNum = INT_MIN;
        int indexToWrite = 0;

        int count = 0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] > maxNum) {
                count++;
                maxNum = nums[i];
                nums[indexToWrite] = nums[i];
                indexToWrite++;
            }
        }

        return count; //we have to return the number of unique numbers.
    }
};