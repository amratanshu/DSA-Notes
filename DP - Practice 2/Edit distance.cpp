https://leetcode.com/problems/edit-distance/

RECURSION ->
My solution ->
Gives TLE !
class Solution {
public:
    int f(string &a, string &b, int i, int j) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;
        
        if (a[i] == b[j]) {
            return f(a, b, i-1, j-1);
        }
        else {
            //replace
            int replace = 1 + f(a, b, i-1, j-1);

            //delete and insert
            int delete1 = 1 + f(a, b, i-1, j);
            int delete2 = 1 + f(a, b, i, j-1);
            
            return min(replace, min(delete1, delete2));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        return f(word1, word2, n-1, m-1);
    }
};