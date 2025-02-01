https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days

My solution ->
try to do on paper. see hints. easy.

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;
        for(auto ele: nums) {
            if (ele != 0) s.insert(ele);
        }

        return s.size();
    }
};