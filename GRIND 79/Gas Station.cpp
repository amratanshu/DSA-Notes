https://leetcode.com/problems/gas-station/description/

GREEDY ->

if the total sum of gas - cost is positive - then a solution exists.

intuition - the place of maximum difference - can be the answer.

INCORRECT VERSION (first attempt)
INCORRECT VERSION (first attempt)
INCORRECT VERSION (first attempt)
INCORRECT VERSION (first attempt)
INCORRECT VERSION (first attempt)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        int ans;
        int maxi = INT_MIN;
        for (int i=0; i<n; i++) {
            sum += gas[i] - cost[i];
            if (gas[i] - cost[i] > maxi) {
                maxi = gas[i] - cost[i];
                ans = i;
            }
        }
        if (sum < 0) return -1;
        return ans;
    }
};

Problem with intuition -> 

if gas - 5 8 2 8
if cost- 6 5 6 6

max diff is at index -> 1 -> but it is negated in the next iteration with -4!!!!

So correct intuition for the index ->

CUMULATIVE of Diff array is not the answer!

we still need to do it in one single pass!

SOLUTION ->

Conditional Cumulative of DIFF array!

basically -> if the cumulative is becoming negative anywhere - that means uss point tak toh car nahi start kar sakte

So make the cumulative zero again - and start doing cumu from next index.

SUM variable is the OVERALL cumulative
CUMULATIVE variable is the running cumulative (think an cumulative of differences array)

CORRECT VERSION ->


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        int ans = 0;
        int cumulative = 0;
        for (int i=0; i<n; i++) {
            sum += gas[i] - cost[i];
            cumulative += gas[i] - cost[i];
            if (cumulative < 0) {
                ans = i + 1;
                cumulative = 0;
            }
        }
        if (sum < 0) return -1;
        return ans;
    }
};