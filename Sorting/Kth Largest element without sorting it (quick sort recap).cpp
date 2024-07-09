https://leetcode.com/problems/kth-largest-element-in-an-array/

Sorting is an easy way - yes

Without sorting - how?
https://takeuforward.org/data-structure/kth-largest-smallest-element-in-an-array/

1. using heap
2. using quick select

Lets recall quick sort first ->
Striver - https://www.youtube.com/watch?v=WIrA4YexLRQ&ab_channel=takeUforward


QUICK SORT implementation with comments ->
class Solution {
public:
    void solve(vector<int> & nums, int low, int high) {
        if (low > high)
            return;
        int pivot = nums[low];
        int i = low;
        int j = high;
        while(i < j) {
            //find the first element from the left - higher than pivot
            while (i < high && nums[i] <= pivot)
                i ++;

            //find the first element from the right - lower than pivot
            //why not nums[j] <= pivot here? - because we can have duplicates. and duplicates we can keep only on one side of the partition - choose whichever u like.
            while (j > low && nums[j] > pivot)
                j --;

            if (i < j)
                swap(nums[i], nums[j]);
        }

        //place the pivot where it crossed and stopped (j is basically the last element of the first partition !)
        swap(nums[j], nums[low]);
        
        solve(nums, low, j - 1);
        solve(nums, j + 1, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        solve(nums, 0, nums.size()-1);
        return nums;
    }
};

QUICK SELECT - > https://www.youtube.com/watch?v=BP7GCALO2v8&ab_channel=Techdose
this is good for searching for a single element.
quick select will not sort the complete array. Quick sort will.

SOLUTION to Kth largest using quick sort ->

This is just a descending version of quick sort

and we keep checking the partition index
If the partition index == k => that means this is the kth largest element - because uske left me saare largest element honge
(thats how the quick sort partition works)

"However, instead of recursing into both sides as in Quicksort, 
quickselect only recurs into one side; whichever one would have our kth largest element."

A guide to quick select -> https://leetcode.com/problems/kth-largest-element-in-an-array/solutions/2180600/a-guide-to-quick-select-java

My version of quick select
class Solution {
public:
    //this recursive method is just the descending version of quick sort
    void solve(vector<int>& nums, int low, int high, int k, int &ans) {
        if (low > high)
            return;
        int pivot = nums[low];
        int i = low;
        int j = high;
        while (i < j) {
            while (i < high && nums[i] >= pivot)
                i++;

            while (j > low && nums[j] < pivot)
                j--;

            if (i < j)
                swap(nums[i], nums[j]);
        }

        // place the pivot where it crossed and stopped (j is basically the last
        // element of the first partition !)
        swap(nums[j], nums[low]);

        if (j == k-1)  {
            ans = nums[j];
            return;
        }

        if (j < k-1) {
            solve(nums, j + 1, high, k, ans);
        }

        if (j > k-1) {
            solve(nums, low, j - 1, k, ans);
        }

        
    }
    int findKthLargest(vector<int>& nums, int k) {
        // use quick select
        int ans;
        solve(nums, 0, nums.size()-1, k, ans);
        return ans;
    }
};

TIME - avg O(N) - varna plain quick sort algo hota toh ye O(NLOGN) hoti
SPACE - avg O(1) - this is quick sort ka in general benefit - (not counting the aux stack space here of course)