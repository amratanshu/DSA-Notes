WRONG SOLUTION

But cant understand why this is not working for [2, 3, 5] 

Dry run also working on paper - unless I am doing something wrong.

My old working solution is also pasted below this bad-solution

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> temp;
        solve(s, candidates, temp, target);
        for (auto itr : s) {
            ans.push_back(itr);
        }
        return ans;
    }

    void solve(set<vector<int>>& s, vector<int> candidates, vector<int>& temp,
               int target) {
        cout << "target is ";
        cout << target << endl;

        for (auto itr : temp) {
            cout << itr;
            cout << ",";
        }
        cout << endl;

        if (target == 0) { // achieved - add this temp to the final answer

            sort(temp.begin(), temp.end());

            s.insert(temp);
            // clear the last element from temp
            if (temp.size() > 0)
                temp.pop_back();

            return;
        }
        if (target < 0) {
            if (temp.size() > 0)
                temp.pop_back();

            return;
        }

        for (int i = 0; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            solve(s, candidates, temp, target - candidates[i]);
        }

        // clear temp here ?
        if (temp.size() > 0)
            temp.pop_back();

        return;
    }
};







Working solution ->

void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
      if (ind == arr.size()) {
        if (target == 0) {
          ans.push_back(ds);
        }
        return;
      }
      // pick up the element 
      if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
      }

      findCombination(ind + 1, target, arr, ans, ds);

    }
class Solution {
public:
    vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
      vector < vector < int >> ans;
      vector < int > ds;
      findCombination(0, target, candidates, ans, ds);
      return ans;
    }
};