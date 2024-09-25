https://leetcode.com/problems/coin-change-ii/

Very slight change from Coin Change

Recurrence will change as --

Base case - if (ind == 0)
    if (sum is possible) - return 1
    else return 0

Actual case-
    notTake = f(ind-1, sum)
    take = 0
    if (take is possible) take = f(ind, sum-arr[ind])
    
    return take + notTake

CODE ->

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // Space Optimised
        vector<int> prev(amount+1,-1),curr(amount+1,-1);
        
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0)
                prev[target] = 1;
            else prev[target] = 0;
        }

        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int notTake = prev[target]; //think
                int take = 0;
                if(coins[ind]<=target){
                    take = curr[target-coins[ind]];
                }
                curr[target]=take + notTake;
            }
            prev=curr;
        }
        
        return prev[amount];
    }
};


ON LEETCODE - handle the overflow error somehow. A previously accepted solution isnt working anymore - WEIRD

there can be a case where take + notTake causes OVERFLOW. Handle it!