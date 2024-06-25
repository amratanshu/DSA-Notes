QUES - https://leetcode.com/problems/sliding-window-maximum/

Striver - https://www.youtube.com/watch?v=CZQGRp93K4k&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=84&ab_channel=takeUforward

CONCEPT -

Create a Deque, Qi of capacity K, that stores only useful elements of current window of K elements. 
An element is useful if it is in current window (not out of bound) and is greater than all other elements on right side of 
it in current window. Process all array elements one by one and maintain Qi to contain useful elements of 
current window and these useful elements are maintained in sorted order. The element at front of the Qi 
is the largest and element at rear/back of Qi is the smallest of current window.

https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

intuition explainted in striver video at 12:50

DECREASING MANNER DECREASING MANNER !!
//using a dequeue to optimise because we want to store elements in a decreasing manner
//consider [1,3,-1,-3,5,3,6,7]
//i=0 store 1 in the back of dq
//i=1 - we dont need to store 3 because this is the bigger ele
//i=2 - add this to the front of dq. Decreasing one can help us because when going to the next window
//it can change the answer always

//everytime window is shifting - we will find our answer at the back of the dequeue
//everytime window is shfiting - remove the element from last window - its is out of bound for this window

//when we reach 5, remove everything that is smaller than 5 - because we dont need them!

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++) {
            //out of bounds check - i-k is the one element from the previous window - simply remove it
            if (!dq.empty() && dq.front() == i-k)
                dq.pop_front();

            //remove all smaller elements from the dq
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            //populate the answers for this window
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }

        return ans;

    }
};