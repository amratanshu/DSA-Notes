3365. Rearrange K Substrings to Form Target String


class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        map<string, int> m;
        int n = s.size();
        int ss = n/k;
        for (int i=0; i<=n-ss; i+=ss) {
            m[s.substr(i, ss)] ++;
        }

        for (int i=0; i<=n-ss; i+=ss) {
            string str = t.substr(i, ss);
            if (m.find(str) == m.end()) return false;

            m[str]--;
        }

        for (auto str: m) {
            if (m[str.first] != 0) return false;
        }
        return true;
    }
};