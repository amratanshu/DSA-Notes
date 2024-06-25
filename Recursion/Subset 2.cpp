Basic rescursion concept.

Personal solution.

Havent seen Striver video yet.

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> result;
        vector<vector<int>> ans;
        solve(result, 0, nums);
        for (auto itr: result) {
            ans.push_back(itr);
        }

        return ans;
    }

    void solve(set<vector<int>> &result, int index, vector<int> nums) {
        //base case
        if (index == nums.size()) { //nothing left to be added
            vector<int> empty;
            result.insert(empty);
            return;
        }
        
        //add this element to all existing vectors and create new ones for them
        vector<vector<int>> toAdd;
        for (auto itr: result) {
            vector<int> t = itr;
            t.push_back(nums[index]);
            toAdd.push_back(t);
        }

        for (auto add: toAdd) {
            result.insert(add);
        }

        //add a vector with this element alone
        vector<int> temp;
        temp.push_back(nums[index]);
        result.insert(temp);
        
        solve(result, index+1, nums);
    }
};