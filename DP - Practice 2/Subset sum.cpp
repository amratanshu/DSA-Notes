https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/

Recursive / Recurrence relation solution ->

public:
    bool recur(int ind, int sum, vector<int> &arr, int n) {
        if (ind == n) return false;
        if (sum == 0) return true;
        if (recur(ind+1, sum, arr, n) || recur(ind+1, sum - arr[ind], arr, n)) return true;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        return recur(0, sum, arr, arr.size());
    }



Dp solution draft -

public:
    bool recur(int ind, int sum, vector<int> &arr, int n) {
        if (ind == n) return false;
        if (sum == 0) return true;
        if (recur(ind+1, sum, arr, n) || recur(ind+1, sum - arr[ind], arr, n)) return true;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        // return recur(0, sum, arr, arr.size());
        int n = arr.size();
        int dp[n][sum+1];
        
        //base condition 1
        for (int i=0; i<=sum; i++) {
            dp[n-1][i] = 0;
        }
        
        //base condition 2
        for (int i=0;i<n;i++) {
            dp[i][0] = 1;
        }
        
        for (int ind=n-2; ind>=0; ind--) {
            
            for (int k=0; k<=sum; k++) {
                
            }
                
            }
        }
    }
