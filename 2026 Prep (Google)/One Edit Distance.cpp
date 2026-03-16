https://leetcode.com/problems/one-edit-distance/description/

Two Pointer - simple intuition but edge cases were a little difficult

Thoughts ->

if (len1 == len2 || len2 == len1 + 1 || len2 == len1 - 1) -- then only a true ans is possible
Otherwise just return false. (because there are more than 2 characters different in the strings)

We are just calculating the count of differences

To handle edge cases one by one - we have added some logic - like the 0 length edge cases logic etc.



class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();

        if (len1 == 0 && len2 == 0) return false;

        if (len1 == len2 || len2 == len1 + 1 || len2 == len1 - 1) {
            int count = 0; //no of different characters
            int i = 0;
            int j = 0;

            while(i < len1 && j < len2) {
                if (s[i] != t[j]) {
                    count++;
                    if (count > 1) return false;

                    if (len1 > len2) i++;
                    else if (len2 > len1) j++;
                    else {
                        i++; j++;
                    }
                }
                else {
                    i++; j++;
                }
            }

            if (count == 1 || abs(len1 - len2) == 1) return true;
            else return false;
        }
        else return false;
    }
};