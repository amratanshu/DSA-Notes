https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=printing-longest-increasing-subsequence

See the solution we did in the previous dp folder - LIS file.

But there (old dp folder) - we printed any one LIS.

Here - we have to print the LIS with elements occuring earlier in the array - so slight tweaks in how we
are maintaining the hash array and backtracking

Do a dry run on paper to understand perfectly

The only condition changed is - see the comment in the code.

vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n, 1);
        vector<int> hash(n);
        
        for (int i=0; i<n; i++) {
            hash[i] = i;
        }
        
        int maxi = 1;
        int lastIndex = 0;
        
        for (int i=0; i<n;i++) {
            for (int prev=0; prev<i;prev++) {
                if (arr[prev] < arr[i]) {
                    if (dp[i] < dp[prev] + 1) { //THIS CONDITION IS CHANGED - do a dry run to understand.
                        hash[i] = prev;
                        dp[i] = dp[prev] + 1;
                    }
                }
            }

            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> LIS;
        LIS.push_back(arr[lastIndex]);
        while(hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            LIS.push_back(arr[lastIndex]);
        }
        reverse(LIS.begin(), LIS.end());
        return LIS;
        
    }