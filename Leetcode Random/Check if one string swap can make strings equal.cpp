https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/?envType=daily-question&envId=2025-02-05

Easy solution

Just count the mismatches and keep the track of the first mismatched characters

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) return false;

        char a = '$', b = '$';
        int count = 0;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                count++;
                
                if (count > 2) return false; // More than two mismatches
                
                if (count == 1) { 
                    a = s1[i]; 
                    b = s2[i]; 
                } else { // count == 2
                    if (s1[i] != b || s2[i] != a) return false;
                }
            }
        }

        return count == 0 || count == 2; // Either identical or exactly one swap possible
    }
};
