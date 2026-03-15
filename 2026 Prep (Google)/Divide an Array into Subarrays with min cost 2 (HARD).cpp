https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/description/

SLIDING WINDOW CONCEPT

NOTE: Solve - Sliding Window Median problem first

SIMILAR solution to median problem - this also uses Multi Set + Sliding Window

HINT 1:
For each i > 0, try each nums[i] as the first element of the second subarray. We need to find the sum of 
k - 2 smallest values in the index range [i + 1, min(i + dist, n - 1)].

This problem is essentially a variation of the "Sliding Window Median" you just solved. Instead of the median, you need to track the sum of the smallest k−2 elements within a window of size dist.

To do this efficiently, youll use two multisets again:

left: Stores the k−2 smallest elements.

right: Stores the rest of the elements in the window.


class Solution {
public:
    long long current_sum = 0;
    int target_size;

    void insertInSets(multiset<int>& left, multiset<int>& right, int ele) {
        left.insert(ele);
        current_sum += ele;

        // Maintain size: if left grows too big, move largest to right
        if (left.size() > target_size) {
            int toMove = *left.rbegin();
            current_sum -= toMove;
            left.erase(prev(left.end()));
            right.insert(toMove);
        }

        // Ensure values are correct: left's max <= right's min
        if (!left.empty() && !right.empty() &&
            *left.rbegin() > *right.begin()) {
            int valL = *left.rbegin();
            int valR = *right.begin();
            current_sum = current_sum - valL + valR;
            left.erase(prev(left.end()));
            right.erase(right.begin());
            left.insert(valR);
            right.insert(valL);
        }
    }

    long long minimumCost(vector<int>& nums, int k, int dist) {
        multiset<int> left, right;
        int n = nums.size();
        target_size = k - 2; // We need k-2 elements in the left multiset
        current_sum = 0;

        // Initial window: indices 2 to dist + 1
        // Note: nums[0] and nums[1] are handled separately to fix the first
        // subarray
        int i = 2;
        while (i <= 1 + dist && i < n) {
            insertInSets(left, right, nums[i]);
            i++;
        }

        // The cost is always nums[0] + nums[first_index_of_window] + sum of k-2
        // smallest in the rest of window
        int windowStart = 1;
        long long min_total_cost = (long long)2e18; // Large initial value

        while (windowStart <= n - (k - 1)) {
            // 1. Calculate the sum for the current window
            // Current window starts at nums[windowStart].
            // We already have the k-2 smallest of the remaining 'dist' range in
            // 'left'.
            min_total_cost = min(min_total_cost, (long long)nums[0] + nums[windowStart] + current_sum);

            // 2. Prepare to slide: If i reached n, we can't add more, but we
            // still slide windowStart
            if (i >= n && windowStart >= n - (k - 1))
                break;

            // 3. SLIDE: Remove the element that was at the start of the "search
            // range" The range of k-2 elements starts at windowStart + 1. So
            // when windowStart slides, we remove nums[windowStart + 1] from our
            // sets.
            int toRemove = nums[windowStart + 1];
            auto it = left.find(toRemove);
            if (it != left.end()) {
                current_sum -= toRemove;
                left.erase(it);
                // Pull from right to maintain target_size
                if (!right.empty()) {
                    int toMove = *right.begin();
                    current_sum += toMove;
                    left.insert(toMove);
                    right.erase(right.begin());
                }
            } else if (!right.empty()) {
                auto itR = right.find(toRemove);
                if (itR != right.end())
                    right.erase(itR);
            }

            // 4. SLIDE: Add the next available element into the range
            if (i < n) {
                insertInSets(left, right, nums[i]);
                i++;
            }

            windowStart++;
        }

        return min_total_cost;
    }
};