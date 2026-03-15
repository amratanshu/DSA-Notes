https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/description/

SLIDING WINDOW CONCEPT

NOTE: Solve - Sliding Window Median problem first

HINT 1:
For each i > 0, try each nums[i] as the first element of the second subarray. We need to find the sum of 
k - 2 smallest values in the index range [i + 1, min(i + dist, n - 1)].


