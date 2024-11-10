https://leetcode.com/problems/rotate-string/description/?envType=daily-question&envId=2024-11-03

O(N^2) is brute force

This is O(N) -> using STL

string::npos is returned when that substring is not found

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        return (s + s).find(goal) != string::npos;
    }
};

using substring ->

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        s = s + s;

        for(int i=0; i<= (s.size() - 1 - goal.size()); i++) {
            if (s.substr(i, goal.size()).compare(goal) == 0) return true;
        }
        return false;
    }
};