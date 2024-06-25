https://leetcode.com/problems/next-permutation/

Observe the pattern in 4 digit array

Concept - Look for First Decreasing Element from the RIGHT !! 

Then you will recognise the pattern 

if no first decreasing integer - reverse the array or simply do sort()

if dec integer found (from the right) - 
In the right side remaining array - start traversing from the right - 
Find the first elemenet just greater than a[index] = index is the index of first decreasing element
1. THEN do a SWAP with the first element on the right
2. reverse FDE (First dec element) ke right side wala remaining array



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find first decreasing element from the right ->
        int fde = -1;
        for (int i=nums.size()-2; i>=0;i--) {
            if (nums[i] < nums[i+1]) {
                fde = i;
                break;
            }                
        }

        if (fde == -1) {
            //reverse and return the array
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i=nums.size()-1; i>fde;i--) {
            if (nums[i] > nums[fde]) {
                swap(nums[i], nums[fde]);
                break;
            }
        }

        reverse(nums.begin() + fde + 1, nums.end());
        return;
    } 
};