https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-all-lcs-sequences

Print all Longest Common Subsequences!!

Use the DP array table which is formed !!

Whenever s1[i] = s2[j] -> we take that in the LCS - that is the point where those letters are considered in the dp

start moving the pointer from the lowermost rightmost point in DP 2D array (i, j)th position

From our recurrence relation (see LCS questions) - we know that -

1. if letters dont match at i, j - the dp at that position answer came from either i-1,j or i, j-1 positions

2. If letters match - we know that this is in the LCS and the answer came from i-1, j-1 position (1 + dp[i-1][j-1]).

See striver video to understand more.

To do this - we have to use Backtracking!!

My Code - First attempt at a solution - (THIS IS CORRECT SOLUTION but GIVES TLE!)

    vector<string> all_longest_common_subsequences(string s1, string s2) {
        //Code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }

        // Use a set to avoid duplicates
        set<string> lcs_set;
        string current_lcs = "";
        backtrack(dp, s1, s2, n, m, current_lcs, lcs_set);

        // Convert set to vector and return sorted result
        vector<string> result(lcs_set.begin(), lcs_set.end());
        sort(result.begin(), result.end());
        return result;
    }
    
    void backtrack(const vector<vector<int>>& dp, const string& s1, const string& s2, int i, int j, string& current_lcs, set<string>& lcs_set) {
        // Base case: if we reach the top or left edge, we add the LCS
        if (i == 0 || j == 0) {
            if (!current_lcs.empty()) {
                string lcs_copy = current_lcs;
                reverse(lcs_copy.begin(), lcs_copy.end());
                lcs_set.insert(lcs_copy); // Add the LCS to the set to avoid duplicates
            }
            return;
        }

        // If characters match, add to the current LCS and move diagonally
        if (s1[i - 1] == s2[j - 1]) {
            current_lcs.push_back(s1[i - 1]);
            backtrack(dp, s1, s2, i - 1, j - 1, current_lcs, lcs_set);
            current_lcs.pop_back(); // Backtrack
        } else {
            // If both paths have the same DP value, explore both paths
            if (dp[i - 1][j] == dp[i][j - 1]) {
                backtrack(dp, s1, s2, i - 1, j, current_lcs, lcs_set);
                backtrack(dp, s1, s2, i, j - 1, current_lcs, lcs_set);
            } 
            // Otherwise, follow the larger DP value
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                backtrack(dp, s1, s2, i - 1, j, current_lcs, lcs_set);
            } else {
                backtrack(dp, s1, s2, i, j - 1, current_lcs, lcs_set);
            }
        }
    }



How to solve TLE in this?

one option : To resolve TLE - we can use memoization in the backtracking step!!

However - I found this code solution on GFG as well - which is accepted --->

Using map !

How are we using a map here?
The key used in mp is a string that uniquely represents the current state of the backtracking process.

Example of Redundant Computation Prevention:
Consider a scenario where the dp[i-1][j] and dp[i][j-1] are both equal to dp[i][j]. 
This means both recursive paths (i-1, j and i, j-1) are valid, and the function will explore both. 
Without memoization, the same state could be revisited multiple times during backtracking, leading to redundant 
computations.

By storing the result for each (i, j, temp) state in mp, we ensure that any duplicate recursive calls are avoided, 
thus improving the efficiency of the solution.

Why is temp part of the key?
The temp string (the partially formed LCS) is included in the key because the same indices i and j might lead to 
different subsequences depending on the characters that have already been added to temp. Thus, to fully capture 
the state of the recursion, temp must be included in the key. This ensures that the function doesnt 
confuse different paths that reach the same i and j but with different subsequences formed so far.

To understand more - ask chat gpt this question with the code given below -
"show an example of 2 strings (and their dp table and keys stored in map) where we will avoid redundant computation using the map.."

class Solution {
  public:
    set<string>st;
    void findAllLcs(int i, int j, string &s, string &t, vector<vector<int>>&dp, string temp, unordered_map<string, bool>&mp){
        if(i == 0 || j == 0){
            st.insert(temp);
            return;
        }
        string key = to_string(i) + " " + to_string(j) + " " + temp;
        if(mp.find(key) != mp.end()) return;
        mp[key] = true;
        if(s[i-1] == t[j-1]){
            temp.push_back(s[i-1]);
            findAllLcs(i-1, j-1, s, t, dp, temp, mp);
            temp.pop_back();
        }
        else if(dp[i-1][j]==dp[i][j] && dp[i][j-1]==dp[i][j]){
           //try both directions
           findAllLcs(i-1, j, s, t, dp, temp, mp);
           findAllLcs(i, j-1, s, t, dp, temp, mp);
        }
        else if(dp[i-1][j]==dp[i][j]){
            findAllLcs(i-1, j, s, t, dp, temp, mp);
        }
        else{
            findAllLcs(i, j-1, s, t, dp, temp, mp);
        }
    }
    vector<string> all_longest_common_subsequences(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1])dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int len = dp[n][m];
        vector<string>ans;
        unordered_map<string, bool>mp;
        findAllLcs(n, m, s, t, dp, "", mp);
        for(auto it : st){
            reverse(it.begin(), it.end());
            ans.push_back(it);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};