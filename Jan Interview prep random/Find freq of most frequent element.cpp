https://leetcode.com/problems/frequency-of-the-most-frequent-element/editorial/?envType=company&envId=tiktok&favoriteSlug=tiktok-all

Sliding window concept - 

https://leetcode.com/explore/interview/card/leetcodes-interview-crash-course-data-structures-and-algorithms/703/arraystrings/4502/

function fn(nums, k):
    left = 0
    curr = 0
    answer = 0
    for (int right = 0; right < nums.length; right++):
        curr += nums[right]
        while (curr > k): /// while (can be any condition to make the subarray invalid - if invalid remove elements from left)
            curr -= nums[left]
            left++

        answer = max(answer, right - left + 1)

    return answer

BASICALLY -> SLIDING WINDOW PSEUDO ALGO ->
function fn(arr):
    left = 0
    for (int right = 0; right < arr.length; right++):
        Do some logic to "add" element at arr[right] to window

        while WINDOW_IS_INVALID:
            Do some logic to "remove" element at arr[left] from window
            left++

        Do some logic to update the answer


SOLUTION TO THIS QUESTION ->

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        //CONCEPT - try to consider each element as the TARGET. uske peeche wale few elements me overall k operations kar ke dekh lo and choose the maximum from them!

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int sumTillNow = 0; //current sum
        int ans = 0;
        for(int right=0; right<n; right++) {
            long target = nums[right]; //target is rightmost element of the window at all times
            sumTillNow += target;

            while((right - left + 1) * target - sumTillNow > k) {
                sumTillNow -= nums[left];
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;

    }
};

