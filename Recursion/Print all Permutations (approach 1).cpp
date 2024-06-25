This is my approach and my code ->

This is basic recursion with no space optimization

There is another approach to this question which is in the file Print all permutations (approach 2).cpp

About this approach ->


If I have to find f(1 2 3)

Basically - 

1 + f(2 3)
2 + f(1 3)
3 + f(1 2)


So at a time - we are taking one element in the permutation and then recursively calling f on the remaining elements

To code this up 

1. Maintain an array which tells u which elements have been taken - active[i] of size n - 0 and 1 will mark which
element is taken or not

2. Put the taken element in a temp array

3. when this temp array becomes of size n - just add it to the answer buddy

4. dont forget to pop back the taken element and reset the active array on its corresponding location

Code -

class Solution {
public: 
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 1) {
            vector<int> t;
            t.push_back(nums[0]);
            ans.push_back(t);
            return ans;
        }

        vector<int> active(nums.size(), 0);
        vector<int> permut;

        solve(ans, active, permut, nums);
        return ans;
    }

    //active contains 1 on the elements which have been taken into the permutation; and 0 otherwise
    void solve(vector<vector<int>> &ans, vector<int> &active, vector<int>& permut, vector<int> nums) {
        if (permut.size() == nums.size()) {
            ans.push_back(permut);
            return;
        }

        for (int i=0;i<nums.size();i++) {
            if (active[i] == 0) {
                permut.push_back(nums[i]);
                active[i] = 1;
                solve(ans, active, permut, nums);
                active[i] = 0;
                permut.pop_back();
            }
        }

    }
};