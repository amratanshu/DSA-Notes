https://leetcode.com/problems/adding-spaces-to-a-string/description/?envType=daily-question&envId=2024-12-03


Note - Use push_back instead of + operator to avoid TLE for append operation.
Just do what you are told. Very simple and easy question.

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";

        int j = 0;
        int i = 0;
        while(i <= s.size() - 1) {
            if (j < spaces.size() && i == spaces[j]) { //add a space here
                ans.push_back(' ');
                j++;
                
            }
            else {
                ans.push_back(s[i]);
                i++;
            }
        }
        return ans;
    }
};