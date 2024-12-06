https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/?envType=daily-question&envId=2024-12-05

Intuition ->

let n be the length for s &'t'
Move i, j both for s, t by using for loop with increment i++, j++
In the inner loop move i until s[i]!='_'
In the inner loop move j until t[j]!='_'
If s[i]!=t[j] return false
If s[i]==t[j]='L' and i<j return false
If s[i]==t[j]='R' and i>j return false
end the nested loop, all conditions for s[i]==t[j] are passed, return true.

class Solution {
public:
    bool canChange(string start, string target) {
        int s = 0, t = 0;
        int n = start.size();
        while(s < n && t < n) {
            while(start[s] == '_' && s < n) {
                s++;
            }
            while(target[t] == '_' && t < n) {
                t ++;
            }

            if (start[s] != target[t]) return false;

            if (start[s] == 'L' && s < t) return false;

            if (start[s] == 'R' && s > t) return false;
            s++; t++;
        }
        
        //check if there are any remaining elements by traversing the non-exhausted pointer
        while (s < n) {
            if (start[s] != '_') return false;
            s++;
        }
        while (t < n) {
            if (target[t] != '_') return false;
            t++;
        }
        return true;

    }
};