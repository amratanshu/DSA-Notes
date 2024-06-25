
https://www.youtube.com/watch?v=m18Hntz4go8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=43&ab_channel=takeUforward
https://leetcode.com/problems/trapping-rain-water/description/

Brute is bad

Better solution -

At any ith index - what is the water stored over that block?

That would depend on - what is the max to the left of this index and what is the max to the right of this index

at any i -> water stored = min(leftMax, rightMax) - A[i]

Brute is - O(n^2)

to do this in 3*O(n) - 

Create 2 new arrays and compute storing leftMax and rightMaxs for a particular index - so create 2 arrays of the same size
O(n) for each array

Then traverse the main list again and use the formula directly.
O(n) for traversing this main list again.

SC is 2(O(N)) in this BETTER solution

BUt in Optimal solution - 
we can even remove this O(N) + O(N) space complexity

Check striver video to understand the logic for this

I didn't understand it by myself. Watch the video again and again





