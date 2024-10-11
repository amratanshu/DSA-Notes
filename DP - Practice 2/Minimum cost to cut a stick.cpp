https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

Recursive solution ->

class Solution {
public:
    unordered_map<int, int> cutDone;

    int solve(int i, int j, vector<int> &cuts) {
        //base case 
        if (i +1 == j) return 0;

        double mini = DBL_MAX;
        for (int k=0; k<cuts.size(); k++) {
            if (!(cuts[k] < j && cuts[k] > i)) continue;
            
            if (cutDone.find(k) != cutDone.end()) //a cut has already been made at this position
                continue;

            //TAKE CASE
            double costForThisCut = j - i;
            cutDone[k] = 1;
            double cost1 = solve(i, cuts[k], cuts);
            double cost2 = solve(cuts[k], j, cuts);
            
            mini = min (mini, costForThisCut + cost1 + cost2);
            
            //NOT TAKE CASE - just continue - do nothing
            cutDone.erase(k);
        }
        if (mini == DBL_MAX) { //means no cut was made in this i to j. no cuts[k] was possible between them - so just return 0
            return 0;
        }
        return (int) mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        // sort(cuts.begin(), cuts.end());
        return solve(0, n, cuts);
    }
};

in the above solutio - ignore the type casting to double. INT se bhi ho hi jaata hai
I was just making some mistake.

Memoizing this Recursive solution ->

This memoization exceeds the memory limit! so we definitely need to optimise further.
Tabulation will help here.

class Solution {
public:
    unordered_map<int, int> cutDone;

    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        //base case 
        if (i +1 == j) return dp[i][j] = 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int k=0; k<cuts.size(); k++) {
            if (!(cuts[k] < j && cuts[k] > i)) continue;
            
            if (cutDone.find(k) != cutDone.end()) //a cut has already been made at this position
                continue;

            //TAKE CASE
            int costForThisCut = j - i;
            cutDone[k] = 1;
            int cost1 = solve(i, cuts[k], cuts, dp);
            int cost2 = solve(cuts[k], j, cuts, dp);
            
            mini = min (mini, costForThisCut + cost1 + cost2);
            
            //NOT TAKE CASE - just continue - do nothing
            cutDone.erase(k);
        }
        if (mini == INT_MAX) { //means no cut was made in this i to j. no cuts[k] was possible between them - so just return 0
            return 0;
        }
        return dp[i][j] = mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        // sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
        return solve(0, n, cuts, dp);
    }
};


our solution is not exactly convertible to TABULATION because of another state variable which is handling the recursion
the unordered map..

Striver solution ->

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        // Create a DP table to store calculated values.
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        for (int i = c; i >= 1; i--) {
            for (int j = 1; j <= c; j++) {
                if (i > j)
                    continue;

                int mini = INT_MAX;

                for (int ind = i; ind <= j; ind++) {
                    // Calculate the cost for making a cut at position 'ind'.
                    int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] +
                              dp[ind + 1][j];

                    mini = min(mini, ans);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][c];
    }
};
