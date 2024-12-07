https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/?envType=daily-question&envId=2024-11-05

Good question

Just a simple catch - see the comment

class Solution {
public:
    int minChanges(string s) {
        //just count the number of 01 or 10 pairs. (increment i by 2)
        int i = 0;
        int count = 0;
        while(i < s.size()) {
            if (s[i] != s[i+1]) {
                count++;
            }
            i += 2;
        }
        return count;
    }
};