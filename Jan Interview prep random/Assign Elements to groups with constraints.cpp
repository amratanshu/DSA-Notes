https://leetcode.com/problems/assign-elements-to-groups-with-constraints/

Create a key to index entry in a map for each ELEMENT

Concept - For every group - search for its divisors in the MAP. 
Divisors - 1 to sqrt(group)

Return the minimum index of all such divisors

Time complexity - O(N∗Sqrt(Max(Groups)))
Space - O(N)

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        map<int, int> m;
        int i = 0;
        for(auto& ele: elements) {
            if (m.find(ele) == m.end()) {
                m[ele] = i;
            }
            i++;
        }
        vector<int> ans;

        for(auto gr: groups) {
            int sqrtVal = sqrt(gr);
            int tempAns = -1;
            for(int i = 1; i <= sqrtVal; i++) {  // Check up to and including sqrtVal
                if (gr % i == 0) {
                    int factor1 = i;
                    int factor2 = gr / i;

                    if (m.find(factor1) != m.end() || m.find(factor2) != m.end()) {
                        int idx1 = (m.find(factor1) != m.end()) ? m[factor1] : INT_MAX;
                        int idx2 = (m.find(factor2) != m.end()) ? m[factor2] : INT_MAX;
                        if (tempAns != -1) tempAns = min(tempAns, min(idx1, idx2));
                        else tempAns = min(idx1, idx2);
                    }
                }
            }
            ans.push_back(tempAns);
        }

        return ans;
    }
};