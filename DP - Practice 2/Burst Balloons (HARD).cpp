https://leetcode.com/problems/burst-balloons/submissions/1418556667/

Recurrence Relation solution ->

class Solution {
public:
    int solve(int i, int j, vector<int>& nums) {
        if (i > j) return 0;

        if (i == j) return nums[i-1] * nums[i] * nums[i+1];
        int maxi = INT_MIN;
        for (int k=i; k<=j; k++) {
            int cost1 = solve(i, k-1, nums);
            int cost2 = solve(k+1, j, nums);
            maxi = max(maxi, cost1 + cost2 + nums[i-1] * nums[k] * nums[j+1]);
        }
        return maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return solve(1, n, nums);
    }
};

Memoization ->

class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>> &dp) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN;
        for (int k=i; k<=j; k++) {
            int cost1 = solve(i, k-1, nums, dp);
            int cost2 = solve(k+1, j, nums, dp);
            maxi = max(maxi, cost1 + cost2 + nums[i-1] * nums[k] * nums[j+1]);
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(1, n, nums, dp);
    }
};

Tabulation solution ->

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n; i>=1; i--) {
            for (int j=1; j<=n; j++) {
                if (i > j) continue;

                int maxi = INT_MIN;
                for (int k=i; k<=j; k++) {
                    int cost1 = dp[i][k-1];
                    int cost2 = dp[k+1][j];
                    maxi = max(maxi, cost1 + cost2 + nums[i-1] * nums[k] * nums[j+1]);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};