3366. Minimum Array Sum

Dynamic programming



class Solution {
public:

    int solve(int i, vector<int>& nums, int k, int op1, int op2, vector<vector<vector<int>>>& dp) {
        if (i < 0) return 0;

        if (dp[i][op1][op2] != -1) return dp[i][op1][op2];

        int ans = nums[i] + solve(i-1, nums, k, op1, op2, dp);

        if (op1) {
            int temp = nums[i];
            if (temp % 2 == 0) temp /= 2;
            else temp = temp / 2 + 1;

            ans = min(ans, temp + solve(i-1, nums, k, op1-1, op2, dp));
        }

        if (op2 && nums[i] >= k) {
            ans = min(ans, nums[i] - k + solve(i-1, nums, k, op1, op2-1, dp));
        }

        if (op1) {
            int temp = nums[i];
            if (temp % 2 == 0) temp /= 2;
            else temp = temp / 2 + 1;

            if (op2 && temp >= k) {
                temp = temp - k;
                ans = min(ans, temp + solve(i-1, nums, k, op1-1, op2-1, dp));
            }
        }

        if (op2 && nums[i] >= k) {
            int temp = nums[i] - k;
            if (op1) {
                if (temp % 2 == 0) temp /= 2;
                else temp = temp / 2 + 1;

                ans = min(ans, temp + solve(i-1, nums, k, op1-1, op2-1, dp));
            }
        }

        return dp[i][op1][op2] = ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(op1+1, vector<int>(op2+1, -1)));
        return solve(n-1, nums, k, op1, op2, dp);
    }
};
