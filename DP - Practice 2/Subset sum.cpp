https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/

Recursive / Recurrence relation solution ->

public:
    bool recur(int ind, int sum, vector<int> &arr, int n) {
        if (ind == n) return false;
        if (sum == 0) return true;
        if (recur(ind+1, sum, arr, n) || recur(ind+1, sum - arr[ind], arr, n)) return true;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        return recur(0, sum, arr, arr.size());
    }
}

WATCH STRIVER SOLUTION IN HIS VIDEO - better explanation and better use of indexes and bounds for understanding..
Dp solution -

public:
bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    
    // Base condition: sum 0 can always be achieved by taking an empty subset.
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Base condition: if we are only allowed to pick the last element
    if (arr[n-1] <= sum) {
        dp[n-1][arr[n-1]] = true;
    }

    // Fill the DP table
    for (int ind = n-2; ind >= 0; ind--) {
        for (int k = 1; k <= sum; k++) {
            // Exclude the current element
            bool notTake = dp[ind+1][k];
            // Include the current element (check if it's within bounds)
            bool take = (k >= arr[ind]) ? dp[ind+1][k - arr[ind]] : false;
            dp[ind][k] = notTake || take;
        }
    }

    return dp[0][sum];
}