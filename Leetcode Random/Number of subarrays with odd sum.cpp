https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/?envType=daily-question&envId=2025-02-25

Method - Prefix Sum with DP

class Solution {
public:
    // note - u dont have to calculate sum, u just have to keep a track of
    // whether the new number makes the sum odd or even
    const int MOD = 1e9 + 7;
    vector<vector<int>> memo;
    
    // this returns the number of odd and even sums with last element as i
    int dp(int i, bool isOdd, const vector<int>& arr) {
        if (i < 0)
            return 0;
        if (memo[i][isOdd] != -1)
            return memo[i][isOdd];

        int countOdd = dp(i - 1, true, arr);
        int countEven = dp(i - 1, false, arr);

        int newOdd, newEven;
        if (arr[i] % 2 == 1) {
            newOdd = countEven + 1;
            newEven = countOdd;
        } else {
            newOdd = countOdd;
            newEven = countEven + 1;
        }

        return memo[i][isOdd] = (isOdd ? newOdd : newEven) % MOD;
    }

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        memo.assign(n, vector<int>(2, -1));

        int result = 0;
        for (int i = 0; i < n; i++) {
            result = (result + dp(i, 1, arr)) % MOD;
        }
        return result;
    }
};
