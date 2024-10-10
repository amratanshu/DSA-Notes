https://leetcode.com/problems/longest-string-chain/

concept is of LIS only.

nothing fancy.

class Solution {
public:
    static bool sizeCompare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), sizeCompare);
        int maxi = 1;
        int n = words.size();

        vector<int> hash(n);
        vector<int> dp(n, 1);

        int lastIndex = 0;
        for (int i=0;i<n;i++) {
            hash[i] = i;
            for (int prev=0;prev<i;prev++) {
                if (isPred(words[prev], words[i])) {
                    if (dp[i] < dp[prev] + 1) {
                        dp[i] = dp[prev] + 1;
                        hash[i] = prev;
                    }
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        return maxi;
    }

    bool isPred(string w1, string w2) {
        if (w1.length() + 1 != w2.length()) return false;

        int i=0, j=0;
        int canSkip = 1; //can skip only one character. if we have to skip two characters - then its not the same string
        while(i < w1.length() && j<w2.length()) {
            if (w1[i] != w2[j] && canSkip) {
                j++;
                canSkip = 0;
                continue;
            }
            else if (w1[i] != w2[j] && !canSkip) return false;
            i++, j++;
        }
        return true;
    }
};