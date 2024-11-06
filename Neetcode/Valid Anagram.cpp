https://leetcode.com/problems/valid-anagram/description/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        map<char, int> m;

        for (char c: s) {
            if (m.find(c) == m.end())
                m[c] = 1;
            else
                m[c] ++;
        }

        for (char c: t) {
            if (m.find(c) == m.end())
                return false;
            else {
                m[c]--;
                if (m[c] < 0) {
                   return false;
            }
            }
        }
        map<char, int>::iterator it = m.begin();

        while (it != m.end()) {
            if (m[it->first] != 0) {
                return false;
            }
            it++;
        }

        return true;
    }
};