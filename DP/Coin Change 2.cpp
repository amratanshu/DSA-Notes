CONCEPT - return number of combinations instead of number of minimum reqd coins 
like we did in COIN CHANGE

Instead of doing min (take, notTake) - just count them take + notTake

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
