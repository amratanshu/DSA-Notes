https://leetcode.com/problems/longest-arithmetic-subsequence/description/

Hint 1 (The Structure): You need to know the longest sequence with difference $d$ ending at index $i$.
 This prevents a sequence at the beginning of the array from accidentally "merging" with a sequence 
 at the end that just happens to have the same difference.Fix: Instead of map<int, int> dp, try 
 vector<map<int, int>> dp(n).


First naive Attempt: Incorrect code ->

 class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        map<int, int> dp; //difference -> length of subseq map
        int maxi = INT_MIN;
        for (int i=1; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                int diff = nums[i] - nums[j];

                if (dp.find(diff) == dp.end()) {
                    dp[diff] = 2;
                }
                else {
                    dp[diff]++;
                    maxi = max(maxi, dp[diff]);
                }
            }
        }
        return maxi;

    }
};


CORRECT CODE ->

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        if (nums.size() <=2 ) return nums.size();

        vector<unordered_map<int, int>> dp(nums.size()); //difference -> length of subseq map

        int maxi = 2;

        //The length at index $i$ with difference $d$ should be whatever the length was at index $j$ with that same difference, plus one.
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                int diff = nums[i] - nums[j];
                
                //did a sequence with this diff end at j (looking back at index j)
                if (dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] = dp[j][diff] + 1;
                }
                else dp[i][diff] = 2;

                maxi = max(maxi, dp[i][diff]);
                
            }
        }
        return maxi;

    }
};
