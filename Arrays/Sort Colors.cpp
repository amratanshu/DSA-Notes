https://leetcode.com/problems/sort-colors/

https://www.youtube.com/watch?v=tp8JIuCXBaU&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=21&ab_channel=takeUforward


Soln 1 - Simply count the number of zero ones and 2 and then re write the array (O2n)


Soln 2 -  DNF - Dutch National Flag Algo - 3 pointer algorithm

Basic intuition which came to me is - 
Swap all zeros towards the starting - one pointer to maintain how many zeroes are in the starting
Swap all 2s towards the ending  - one pointer to maintain how many 2s are there now there at the end
Third pointer - i - for iteration


Striver intuition - 
3 pointers -
low
mid 
high 

0 se low - 1 tak 0 honge
low se mid - 1 tak 1 honge
high + 1 se n-1 (last) tak 2 honge

Starting me - zeroes
Fir - 1s
Fir mid se high tak - unsorted array
high+1 ke baad 2s

Shuru me mid is 0 and high is n-1 because starting me the complete array is unsorted

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //easy solution -
        //count the number of 0s 1s and 2s - and overwrite the array.

        //one pass solution using swapping -

        //approach - 
        //swap all 0s with starting index (a pointer)
        //swap all 2s with ending index (a separate pointer)

        int u = 0;
        int v = nums.size()-1;
        int i = 0;
        while (i<=v) {
            if (nums[i] == 0) {
                swap(nums[i], nums[u]);
                u++;
                i++;
            }

            else if (nums[i] == 1)
                i++;

            else if (nums[i] == 2) {
                swap(nums[i], nums[v]);
                v--;
            }
        }
        // return nums;
    }
};