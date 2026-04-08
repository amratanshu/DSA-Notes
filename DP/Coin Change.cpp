https://leetcode.com/problems/coin-change/

Concept: 2D DP - 

Take it many times !

Recurrence Relation f(index, targetValue)
f() is calculating the min number of coins to fulfill this target till index 

forming the recurrence relation ---> 
f(index, target) {

    //base cases: 

    if (index==0) {
        if (target%a[i] == 0)
            returnn target/a[i];
        else
            return 1e9; //instead of INT_MAX, we wrote 1e9 to avoid any overflow because 
            //if any of the function gives INT_MAX - then we can have 1 + INT_MAX - which is OVERFLOW from int
            //hence 1e9 safely handling it here.

            
    }
    int notTake = 0 + f(ind-1, T);

    int take = INT_MAX

    if (coins[ind] <= T)
        take = 1 + f(index, T- coins[index]) //This is the CATCH !!

    return min(take, notTake)

}

OVERFLOW TRICK - we used 1e9 to avoid overflow. because somewhere we expected INT_MAX+1
Another trick to avoid this - assign to INT_MAX - 1. :)))

CATCH: In the "take" line - if we did f(index-1, ...) - then it would mean that we are 
picking the ith coin only ONCE. We dont want that. We are restricting ourselves.

THUMB RULE -> Whenever there is an "infinite supply" OR "multiple use" such statements
of anything like here - COINS, 
we can call back on the f(same index , remaining target)

That means we can pick it again to fulfill that index 

And this doesnt mean - that recursion is not moving backward only now..NO

It will move because if ith coin is denomination 3
and we call (i, 8) 
then we call (i, 5)
then we call (i, 2) ... yahan end hona hi hai.


MULTIPLE SOLUTIONS - See the last one for FINAL !!!


RECURSION ->
class Solution {
public:

    int util(vector<int>& coins, int amount, int n)
    {
        if(n==0 || amount==0)
            return (amount==0) ? 0 : INT_MAX-1;

        if(coins[n-1]<=amount)
            return min( 1 + util(coins, amount-coins[n-1], n), util(coins, amount, n-1));

        else
            return util(coins, amount, n-1);

    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = util(coins, amount, n);
        return (ans == INT_MAX-1 ) ? -1 : ans;
    }
};



MEMOIZATION ->
class Solution {
public:

    int dp[13][10001];

    int util(vector<int>& coins, int amount, int n)
    {
        if(n<=0 || amount<=0)
            return (amount==0) ? 0 : INT_MAX-1;

        if( dp[n][amount] !=-1 )
            return dp[n][amount];

        if(coins[n-1]<=amount)
            return dp[n][amount] = min( 1 + util(coins, amount-coins[n-1], n), util(coins, amount, n-1));

        else
            return dp[n][amount] = util(coins, amount, n-1);

    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int n = coins.size();
        int ans = util(coins, amount, n);
        return (ans == INT_MAX-1 ) ? -1 : ans;
    }
};

SPACE OPTIMIZED - only storage
class Solution {
public:

    int coinChange(vector<int>& coins, int sum) {
        int n=coins.size();
        // Space Optimised
        vector<int> prev(sum+1,-1),curr(sum+1,-1);
        for(int target=0;target<=sum;target++){
            if(target%coins[0]==0)  prev[target]=target/coins[0];
            else prev[target]=1e9;
        }
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=sum;target++){
                int notTake = 0+prev[target];
                int take=INT_MAX;
                if(coins[ind]<=target){
                    take=1+curr[target-coins[ind]];
                }
                curr[target]=min(take,notTake);
            }prev=curr;
        }
        if(prev[sum]>=1e9){return -1;}
        else return prev[sum];
    }
};