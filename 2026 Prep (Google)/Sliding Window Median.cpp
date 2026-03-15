https://leetcode.com/problems/sliding-window-median/description/

This is a Sliding Window problem as well obviously

can brute force easily by using sliding window using a MULTISET.. (that would be O(NK))

Better solution - would be using 2 multisets (one for left smaller array segment, and one for right half which is the bigger array segment of a window)

Approach
Use two multisets (left and right) to maintain a balanced window:
left stores the smaller half (including the median if k is odd).
right stores the larger half.
Maintain balance between both sets:
Insert numbers into left or right while ensuring left has at most one more element than right.
If necessary, move elements between sets to maintain order.
Compute the median:
If k is odd, the median is the maximum of left.
If k is even, the median is the average of the max of left and the min of right.
Slide the window:
Remove the outgoing element from the appropriate set.
Rebalance if necessary.
Complexity
Time Complexity:
O(nlogk) – Each insertion and deletion in a multiset takes O(logk), and we perform this operation n times.
Space Complexity:
O(k) – We maintain two multisets of size k.

class Solution {
public:
    void insertInSets(multiset<int>& left, multiset<int>& right, int ele) {
        if (left.empty() || left.size() <= right.size()) {
            left.insert(ele);
        } else
            right.insert(ele);

        // rebalance here if required
        // if left ka last ele is bigger than right ka first ele, then rebalance
        // na
        if (!right.empty() && *left.rbegin() > *right.begin()) {
            int temp1 = *left.rbegin();
            int temp2 = *right.begin();
            left.erase(left.find(temp1));
            right.erase(right.find(temp2));
            right.insert(temp1);
            left.insert(temp2);
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> left, right;
        int n = nums.size();
        vector<double> ans;

        int i = 0;
        // do this for the first k elements

        int firstEleIndex = 0; // index of the first element of the window
        while (i < k) {
            insertInSets(left, right, nums[i]);
            i++;
        }

        // now k elements are in the sets (window is filled, now just alter the
        // windows)

        while (i <= n) {
            // calculate the median value for this window
            double med;
            if (left.size() == right.size()) {
                med = *left.rbegin()*1.0 + *right.begin()*1.0;
                med = med / 2.0;
                ans.push_back(med);
            } else {
                ans.push_back((double)*left.rbegin());
            }

            // SLIDE the window now
            // code for deleting the first element of the window
            if (left.find(nums[firstEleIndex]) != left.end()) {
                left.erase(left.find(nums[firstEleIndex]));
            } else {
                right.erase(right.find(nums[firstEleIndex]));
            }
            firstEleIndex++; //Window is sliding
            if (i<n)
                insertInSets(left, right, nums[i]);
            i++;
        }

        return ans;
    }
};