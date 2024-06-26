https://leetcode.com/problems/longest-common-prefix/submissions/1300823570/

Sorting helps a lot - after sorting u just have to compare first and last string

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest = "";

        sort(strs.begin(), strs.end());

            if (strs.size() == 1) return strs[0];

        if (strs.size() == 0)
            return longest;

        string first = strs[0];
        string last = strs[strs.size()-1];

        for (int i = 0; i < first.length(); i++) {
            if (first[i] == last[i]) {
                longest += first[i];
            } else {
                break;
            }
        }

        return longest;
    }
};