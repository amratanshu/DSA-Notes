https://leetcode.com/problems/palindrome-partitioning-ii/description/

Recursive solution ->

class Solution {
public:
    bool isPalindrome(int i, int j, string s) {
        while(i <j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

    int solve(int i, int j, string &s) {
        if (i >= j) return 0;
        if (isPalindrome(i, j, s)) return 0;

        int mini = INT_MAX;
        for (int k=i; k<=j; k++) {
            //making the cut at k position
            // Reason : If left substring becomes palindrome then there is no need to partition it further (which in turn reduces the number of recursive calls)
            if (isPalindrome(i, k, s)) {
                mini = min (mini, 1 + solve(k+1, j, s));
            }
        }
        
        return mini;
    }

    int minCut(string s) {
        return solve(0, s.size()-1, s);
    }
};

Memoization ->

Memoization is accepted except in one case which gives Memory limit exceeded on LC

class Solution {
public:
    bool isPalindrome(int i, int j, string s) {
        while(i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

    int solve(int i, int j, string &s, vector<vector<int>> &dp) {
        if (i >= j) return 0;
        if (isPalindrome(i, j, s)) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int k=i; k<=j; k++) {
            //making the cut at k position
            // Reason : If left substring becomes palindrome then there is no need to partition it further (which in turn reduces the number of recursive calls)
            if (isPalindrome(i, k, s)) {
                mini = min (mini, 1 + solve(k+1, j, s, dp));
            }
        }
        
        return dp[i][j] = mini;
    }

    int minCut(string s) {
        vector<vector<int>> dp (s.size(), vector<int>(s.size(), -1));
        return solve(0, s.size()-1, s, dp);
    }
};

Tabulation ->

here - we have just tabulated the above memoized approach.

But - this solution also gives TLE in some cases.
How to optimize further? given below this solution ->

int minCut(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        // base case is covered when we initialized everything in the dp array to 0
        int n = s.size();
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (isPalindrome(i, j, s)) {
                    dp[i][j] = 0;
                    continue;
                }
                int mini = INT_MAX;
                for (int k = i; k <= j; k++) {
                    if (isPalindrome(i, k, s)) {
                        mini = min(mini, 1 + dp[k+1][j]);
                    }
                }
                dp[i][j] = mini;
            }
        }
        return dp[0][n-1];

    }


OPTIMIZE FURTHER ->

isPalindrome takes a lot of time - for every i and j

if u see carefully - we can even memoize this recursive function!!

Also - as in this DP solution - we use only the dp[k+1][j] wala part - we can even make this as a single dimension DP arr.

How to write the solution now?

