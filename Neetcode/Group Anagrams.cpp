https://leetcode.com/problems/group-anagrams/description/

solution using sorting each string and putting in a map - 

O(N * MLogm)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> m;

        for(int i=0; i<strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            m[str].push_back(i);
        }
        vector<vector<string>> ans;
        for (auto itr: m) {
            vector<string> temp;
            for (auto index: itr.second) {
                temp.push_back(strs[index]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};