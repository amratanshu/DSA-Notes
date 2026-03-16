https://leetcode.com/problems/jump-game/description/?envType=company&envId=google&favoriteSlug=google-three-months

Simple greedy ->

O(N) - Best Solution

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i=0; i<nums.size(); i++) {
            if (i > reach) return false;
            else reach = max(reach, i + nums[i]);
        }
        return true;
    }
};

DP Solution ->

Check LC editorial online once (Although DP solution would be O(N^2))

For every element in the array, say i, 
we are looking at the next nums[i] elements to its right aiming to find a GOOD index. 
nums[i] can be at most n, where n is the length of array nums.

enum Index { GOOD, BAD, UNKNOWN };
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<Index> memo(nums.size(), UNKNOWN);
        memo[memo.size() - 1] = GOOD;
        for (int i = nums.size() - 2; i >= 0; i--) {
            int furthestJump = min(i + nums[i], (int)nums.size() - 1);
            for (int j = i + 1; j <= furthestJump; j++) {
                if (memo[j] == GOOD) {
                    memo[i] = GOOD;
                    break;
                }
            }
        }
        return memo[0] == GOOD;
    }
};