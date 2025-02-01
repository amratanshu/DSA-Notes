https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Simple Sliding window concept

Just Follow the sliding window template

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        set<char> m;
        int left = 0;
        int len = 0;
        for(int right=0; right<s.size(); right++) {
            
            while(m.find(s[right]) != m.end()) { //does not satisfy condition - remove left from the window
                m.erase(s[left]);
                left ++;
            }

            m.insert(s[right]);
            len = max(len, right - left + 1);
        }
        return len;
    }
};