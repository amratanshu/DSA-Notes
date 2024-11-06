https://leetcode.com/problems/partition-labels/
https://neetcode.io/problems/partition-labels

Intuition - do a dry run on paper

for every character - make a hashmap and store the last index it occurs on

iterate on the string again - and iterate till a limit (temp variable)
whenever you get a char whose last index is greater than this limit - increase the working window

whenever i reaches this limit number - this can be one substring - because iske pehle ke saare characters iss limit tak
confined reh sakte hain..

O(N) time and space complex.

class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> m;
        int n = s.size();
        for(int i=0; i<n;i++) {
            m[s[i]] = i;
        }

        vector<int> ans;
        // ans.push_back(m[s[0]]);
        int i = 0;
        int temp = INT_MIN;
        while(i < n) {
            temp = max(temp, m[s[i]]);
            if (i == temp) { //can move to the next substring
                cout<<"pushing here\n";
                ans.push_back(temp);
            }
            i++;
        }

        //no we have the end indexes of all substrings in the ans array
        //lets calculate their lengths
        for (int i=ans.size()-1; i>=1; i--) {
            ans[i] = ans[i] - ans[i-1];
        }
        ans[0]++;
        return ans;
    }
};