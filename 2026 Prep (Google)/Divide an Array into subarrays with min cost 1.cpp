https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/

Pretty Simple to solve

No need to sort all the elements.

First element of the array will always be added in the the resulting sum. Why? Because it will always be part of the one of the subarrays.

Find out the two minimum elements from 1 to n, they will make your second and third subarray.

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        //find out two smallest elements except the first one

        int mini = INT_MAX;
        int mini2 = INT_MAX;

        for (int i=1; i<nums.size(); i++) {
            if (nums[i] < mini) {
                mini2 = mini;
                mini = nums[i];
            }
            else if (nums[i] < mini2) {
                mini2 = nums[i];
            }
        }

        return nums[0] + mini + mini2;
    }
};