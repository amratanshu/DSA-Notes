https://leetcode.com/problems/assign-cookies/

g -> children
s -> cookies

Recurrence Relation ->

    int solve(int i,int j,vector<int>& g, vector<int>& s,vector<vector<int>>&dp){
        if (i < 0 || j < 0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int nottake = solve(i-1,j,g,s,dp);//skip cookie
        int take=INT_MIN;
        if(g[i]<=s[j]){
            take=1+solve(i-1,j-1,g,s,dp);
        }
        return dp[i][j]=max(take,nottake);
    }


DP solution - shows time limit exceeded --> 

Greedy is better for this problem!

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int nchild = g.size();
        int ncookie = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        vector<int> prev(ncookie + 1, 0);
        vector<int> curr(ncookie + 1, 0);

        //note: base case for dp has already been covered when we assigned it to 0 above

        for (int indchild = 1; indchild<=nchild; indchild++) {
            //reapply base case every time for this one - rest will be populated in the loop
            curr[0] = 0;
            for (int indcookie = 1; indcookie<=ncookie; indcookie++) {
                int notTake = prev[indcookie];
                int take = 0;
                if (g[indchild-1] <= s[indcookie-1]) take = 1 + prev[indcookie-1];

                curr[indcookie] = max(take, notTake);
            }
            prev = curr;
        }
        return curr[ncookie];
        
    }
};


Why Greedy Is Better
The key observation for this problem is that once the children and cookies are sorted, 
you can simply iterate through both lists to maximize the number of children that can be content. 
There's no need to calculate intermediate states for each possible combination of cookies and children (as youre doing with the DP approach).

SIMPLE GREEDY SOLUTION for this ->

int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort the greed factors and the cookie sizes
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0, cookie = 0;
        // Try to satisfy each child with the smallest available cookie
        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                // If the cookie can satisfy the child's greed, move to the next child
                child++;
            }
            // Move to the next cookie in either case
            cookie++;
        }

        return child; // This represents the number of content children
    }