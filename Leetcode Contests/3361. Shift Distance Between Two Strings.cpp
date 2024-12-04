3361. Shift Distance Between Two Strings


Not really DP

Just a recursive solution with greedy selection of lowest cost. Read the question carefull as cost changes 
with each change in s[i].

variable og is just to restore the original value of s[i]. BACKTRACKING!

class Solution {
public:
    long long solve(int i, string &s, string &t, vector<int>& nextCost, vector<int>& previousCost) {
        if (i < 0) return 0;
        if (s[i] == t[i]) return solve(i - 1, s, t, nextCost, previousCost);

        //greedily select what to do (go ahead or backward)

        long long aheadCost = 0;
        long long backCost = 0;

        if (s[i] < t[i]) {
            char og = s[i];
            while(s[i] != t[i]) {
                aheadCost += nextCost[s[i]-'a'];
                s[i]++;
            }
            s[i] = og;
            while(s[i] != t[i]) {
                backCost += previousCost[s[i]-'a'];
                if (s[i] == 'a') s[i] = 'z';
                else s[i]--;
            }
            s[i] = og;
        }
        else {
            char og = s[i];
            while(s[i] != t[i]) {
                aheadCost += nextCost[s[i]-'a'];
                if (s[i] == 'z') s[i] = 'a';
                else s[i] ++;
            }
            s[i] = og;
            while(s[i] != t[i]) {
                backCost += previousCost[s[i]-'a'];
                s[i]--;
            }
            s[i] = og;
        }

        long long recurse = solve(i-1, s, t, nextCost, previousCost);
        return aheadCost < backCost? aheadCost + recurse: backCost + recurse;
    }

    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        return solve(s.size() - 1, s, t, nextCost, previousCost);
    }
};
