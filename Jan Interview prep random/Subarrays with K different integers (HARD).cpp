https://leetcode.com/problems/subarrays-with-k-different-integers/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days

Sliding window again?

GOOD QUESTION
HARD

Read  Leetcode Editorial for this one.

One way - 
Counting subarrays which have less than or equal to K distinct elements - solve this using sliding window
For our question - we need exact K -  so do return slidingWindowAtMost(nums, k) - slidingWindowAtMost(nums, k - 1);

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindowAtMost(nums, k) - slidingWindowAtMost(nums, k - 1);
    }

private:
    // Helper function to count the number of subarrays with at most k distinct elements.
    int slidingWindowAtMost(vector<int>& nums, int distinctK) {
        // To store the occurrences of each element.
        unordered_map<int, int> freqMap;
        int left = 0, totalCount = 0;

        // Right pointer of the sliding window iterates through the array.
        for (int right = 0; right < nums.size(); right++) {
            freqMap[nums[right]]++;

            // If the number of distinct elements in the window exceeds k,
            // we shrink the window from the left until we have at most k distinct elements.
            while (freqMap.size() > distinctK) {
                freqMap[nums[left]]--;
                if (freqMap[nums[left]] == 0) 
                    freqMap.erase(nums[left]);
                left++;
            }

            // Update the total count by adding the length of the current subarray.
            totalCount += (right - left + 1);
        }
        return totalCount;
    }
};


Another way - direct one-pass of Sliding window ->

Read editorial to understand.

class Solution {
   public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Array to store the count of distinct values encountered
        vector<int> distinctCount(nums.size() + 1, 0);

        int totalCount = 0;
        int left = 0;
        int right = 0;
        int currCount = 0;

        while (right < nums.size()) {
            // Increment the count of the current element in the window
            if (++distinctCount[nums[right++]] == 1) {
                // If encountering a new distinct element, decrement K
                k--;
            }

            // If K becomes negative, adjust the window from the left
            if (k < 0) {
                // Move the left pointer until the count of distinct elements
                // becomes valid again
                --distinctCount[nums[left++]];
                k++;
                currCount = 0;
            }

            // If K becomes zero, calculate subarrays
            if (k == 0) {
                // While the count of left remains greater than 1, keep
                // shrinking the window from the left
                while (distinctCount[nums[left]] > 1) {
                    --distinctCount[nums[left++]];
                    currCount++;
                }
                // Add the count of subarrays with k distinct elements to the
                // total count
                totalCount += (currCount + 1);
            }
        }
        return totalCount;
    }
};