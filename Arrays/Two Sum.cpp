https://leetcode.com/problems/two-sum/


After brute force - Hashing is the BETTER Solution ->

My Hashmap approach CODE -> 

Just keep the indices of the elements in a hashmap
And while putting the numbers - just find if there exists a target - nums[i] in the hashmap

But do remember - handle the duplicate case as well

As in if target = 6 -> we will return the indices of 3 - in both places of the answer vector - 
we dont want to do this - so handle this


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> m;
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i); // indices stored

            // if already found in the hashmap ->
            if (m.find(target - nums[i]) != m.end()) {
                // handle duplicacy here as well ->
                if (nums[i] == target - nums[i]) {
                    if (m[nums[i]].size() > 1) {
                        temp.push_back(m[nums[i]][0]);
                        temp.push_back(m[nums[i]][1]);
                        sort(temp.begin(), temp.end());
                        return temp;
                    }

                } else { //normal case
                    temp.push_back(m[nums[i]][0]);
                    temp.push_back(m[target - nums[i]][0]);
                    sort(temp.begin(), temp.end());
                    return temp;
                }
                
            }
        }

        return temp;
    }
};


TC - O nlogn
SC - O n

If interviewer said - Dont use a map and solve it. (even though the time complexity will remain the same - nlogn)


Optimal way without using a map -> GREEDY approach - using two pointers

1. Sort the array - nlogn
2. take two pointers - i in the starting and j in the ending
3. If sum < target - i++ , if sum > target - j-- , else if same - you found it !

But if we sort - the indices will be lost

So - save the indices in some other data structure - 

[ [1, 0] [ 4, 1]] ... etc

This is not the best approach because space complexity badh jayegi.

If we just have to return YES or NO - the map approach is the best approach to solve the problem Time and Space complexity wise

