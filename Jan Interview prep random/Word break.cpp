https://leetcode.com/problems/word-break/

check if a long string can be segmented into multiple words

Dynamic prog to test out all scenarios

My solutions ->

Recursion ->

class Solution {
public:
    //dynamic prog
    bool solve(int i, string &s, unordered_map<string, int> & dict) {
        if (i >= s.size()) return true;

        for(int len=1; len<=s.size()-i; len++) {
            //check if substring of different possible lengths
            string temp = s.substr(i, len);
            if (dict.find(temp) != dict.end()) { //found in word dict
                if (solve(i+len, s, dict)) return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> m;
        for(auto word: wordDict) {
            m[word]++;
        }

        return solve(0, s, m);
    }
};


Memoization ->

class Solution {
public:
    unordered_map<int, bool> dp; // Memoization table

    bool solve(int i, string &s, unordered_set<string> &dict) {
        if (i == s.size()) return true; // Successfully segmented
        if (dp.find(i) != dp.end()) return dp[i]; // Return memoized result

        for (int len = 1; len <= s.size() - i; len++) {
            string temp = s.substr(i, len);
            if (dict.find(temp) != dict.end() && solve(i + len, s, dict)) {
                return dp[i] = true; // Store result
            }
        }
        return dp[i] = false; // Store failure
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); // Faster lookup
        return solve(0, s, dict);
    }
};


Tabulation DP solution ->

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); // Faster lookup
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Base case: Empty string is always valid

        // Iterate over the length of the string
        for (int i = 1; i <= n; i++) {
            // Try breaking at every possible position j
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break; // No need to check further if a valid segmentation is found
                }
            }
        }
        return dp[n]; // The answer is whether we can segment the full string
    }
};
