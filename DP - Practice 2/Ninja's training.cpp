https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training

The no of activites is fixed at 3!

Recurrence relation function for this ->

f(ind, last) ->

we're calling f(n-1, 3) - because for the first time - the inner loop will check all activities then - even for the last
index.

  public:
  
    int recurr(int ind, int last, vector<vector<int>> &arr, int n) {
        if (ind == 0) {
            //no where to go back - just perform the highest task now
            int maxi = 0;
            for (int i=0;i<=2;i++) {
                if (last != i) {
                    maxi = max(maxi, arr[0][i]);
                }
            }
            return maxi;
        } 
        else {
            int maxi = 0;
            for (int i=0; i<=2;i++) {
                if (last != i) {
                    maxi = max(arr[ind][i] + recurr(ind-1, i, arr, n), maxi);
                }
            }
            return maxi;
        }
    }
    
    int maximumPoints(vector<vector<int>>& arr, int n) {
        int a = recurr(n-1, 3, arr, n);
        return a;
    }


Dynamic programming solution for this problem ->

Without the optimisation of saving only the last used row -->

    int maximumPoints(vector<vector<int>>& arr, int n) {
        int dp[n][3];
        
        for (int i=0;i<3;i++) {
            dp[0][i] = arr[0][i];
        }
        
        for (int i=1; i<n;i++) {
            for (int j=0; j<3; j++) {
                //this j activity is done on the last day
                int maxi = 0;
                for (int k=0;k<3;k++) {
                    if (k != j) {
                        maxi = max(maxi, arr[i][j] + dp[i-1][k]);
                    }
                }
                dp[i][j] = maxi;
            }
        }
        
        int a = dp[n-1][0];
        int b = dp[n-1][1];
        int c = dp[n-1][2];
        return max(a, max(b, c));
    }
