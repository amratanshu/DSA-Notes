https://leetcode.com/problems/flip-string-to-monotone-increasing/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days

Hint - Dynamic programming - Does not strike immediately

Good question ->

If a string is monotone incr - any of its prefixes is also monoton incr.

if s[i - 1] = '1', then we have dp[i] = dp[i - 1] - because we can append a 1 at the end and it will still be monoton incr.

if s[i-1] = '0' - flip or not flip.
if we flip - just 1 + dp(i-1)
if we dont flip - we have to flip all the 1s before this. (all 1s till now to make this string all 0s - so that is monotonic)


class Solution {
public:
    int minFlipsMonoIncr(string s) {
        //dynamic programming

        int count1 = 0;
        int dp = 0; //for first element only as prefix - base case = [1] or [0] is already monotonic
        for(int i=0; i<s.size(); i++) {
            if (s[i] == '1') count1++;
            else {
                //flip
                int flip = 1 + dp;
                int notFlip = count1;
                dp = min(flip, notFlip);
            }
        }
        return dp;
    }
};