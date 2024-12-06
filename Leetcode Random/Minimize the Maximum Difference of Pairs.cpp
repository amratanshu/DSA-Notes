https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

Use binary search here. Similar to aggressive cows wale concept ka binary search.

sort the array

the max possible difference is the diff of last and first element (abs)

So our answer lies between 0 and maxDiff (which we find using binary search)

How does binary search work ?

For every mid value - we check if it is a valid one

isValid -> we check if for this value of maxDiff (mid) - we find p pairs in the array which have difference
less than this value. If yes - this is a valid value - means this maxDiff is possible - so ya toh ye answer hoga
ya is se koi chota number answer hoga.

So when we find a valid value - we start looking in the left half of our binary search bounds


class Solution {
public:
    bool isValid(vector<int>& nums, int p, int mid) {
        int i = 1;
        int n = nums.size();
        int countPairs = 0;
        //try to check if there are p pairs (check adjacent ones because now the aray is sorted) with difference less than mid.
        while(i < n) {
            int diff = abs(nums[i] - nums[i-1]);
            if (diff <= mid) {
                countPairs ++;
                if (countPairs == p) return true;

                i = i + 2; //distinct pairs - so go to the next pair now
            }
            else {
                i++;
            }
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        //find the max possible difference in the sorted array
        if (p == 0) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxDiff = nums[n-1] - nums[0];
        // for (int i=1; i<n;i++) {
        //     maxDiff = max(maxDiff, abs(nums[i] - nums[i-1]));

        // }    
        int low = 0;
        int high = maxDiff;
        int ans = INT_MAX;
        int mid;
        //do binary search using this now ->
        while(low <= high) {
            mid = (low + high)/2;

            if (isValid(nums, p, mid)) { //look in left array as even a smaller value of mid is possible
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
        
    }
};