https://leetcode.com/problems/partition-array-for-maximum-sum/description/

Dynamic programming -

FRONT PARTITION LOGIC - see striver to understand more.

Recurrence relation solution ->

class Solution {
public:
    int solve(int i, int k, vector<int> &arr) {
        if (i == 0) return 0;

        int maxEle = 0;
        int ans = 0;

        for (int j = i; j >= max(1, i - k + 1); j--) {
            maxEle = max(maxEle, arr[j - 1]);
            int partitionSize = i - j + 1;

            // Calculate the sum for this partition
            int sumOfEles = maxEle * partitionSize;
            int remaining = solve(j - 1, k, arr);

            ans = max(ans, sumOfEles + remaining);
        }
        return ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        return solve(n, k, arr);
    }

};

Memoized easy - 

class Solution {
public:
    int solve(int i, int k, vector<int> &arr, vector<int> &dp) {
        if (i == 0) return dp[i] = 0;

        int maxEle = 0;
        int ans = 0;

        if (dp[i] != -1) return dp[i];

        for (int j = i; j >= max(1, i - k + 1); j--) {
            maxEle = max(maxEle, arr[j - 1]);
            int partitionSize = i - j + 1;

            // Calculate the sum for this partition
            int sumOfEles = maxEle * partitionSize;
            int remaining = solve(j - 1, k, arr, dp);

            ans = max(ans, sumOfEles + remaining);
        }
        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return solve(n, k, arr, dp);
    }

};