3371. Identify the Largest Outlier in an Array

O(N) time and O(N) space solution - use a set to store all elements
Sum all of them up
Traverse the arr again and see if any element can be an outlier

Use the equation - TOTALSUM = outlier + 2 * sum


For more optimization ->
O(N) time and O(1) space ->

Store the maximum outlier found.
https://leetcode.com/problems/identify-the-largest-outlier-in-an-array/solutions/6098980/beats-100-o-n-and-o-1-2-solutions-explained-optimized-solution/

MY O(N) time and O(N) space SOLUTION ->


class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> m;
        int maxOutlier = INT_MIN;
        for (auto ele: nums) {
            sum += ele;
            m[ele]++;
        }

        cout<<sum;
        for (auto ele:nums) {
            int sum_double = sum - ele;
            if (sum_double % 2 != 0) continue;
            
            sum_double/=2;
            //remove this outlier from the map
            m[ele]--;
            if (m[ele] == 0) m.erase(ele);
            if (m.find(sum_double) != m.end()) {
                maxOutlier = max(maxOutlier, ele);
            }
            if (m.find(ele) == m.end(ele)) m[ele] = 1;
        }
        return maxOutlier;
    }
};
