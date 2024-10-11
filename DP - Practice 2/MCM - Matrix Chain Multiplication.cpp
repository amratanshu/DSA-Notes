https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=matrix-chain-multiplication


CONCEPT ->

The arr is given as ->


ARR - 40 20 30 10 30

There are N-1 = 4 Matrices 

For matrix i - the dimensions are arr[i-1] x arr[i]

ARR - 40 20 30 10 30
Matri    M1 M2 M3 M4

Now we want to multiply 4 matrices within each other in a chain

So lets just consider a pointer in the beginning and one pointer in the end.

i and j

i = 1 == for matrix 1
j = N-1 == for last matrix

Now - we can partition the multiplication as we want. 

So consider a point k - which will partition the i to j window into two parts

k will go from i to j-1 - so the partitions are (i to k) and (k+1 to j)

NOTE - u can have k go from i+1 to j as well - just how u partition will change.

Also - if a partition has a single matrix - no multiplication is involved in it - hence return 0 (this is our base case)

Now - these two partitions will require P1 and P2 multiplications.

But in the end - both partitions will give final 2 matrixes which need to be multiplied - and they WILL be compatible!
because we are not messing up the chain..

and we also know the size of the resultant two matrices. 
Hence we also know the no of operations required to multiply these 2 final matrices.
=== int multiplyPartitions = arr[i-1] * arr[k] * arr[j];

ITS just a chain at the end of the day.

Thats how our recurrence relation will form - 


Recurrence Relation solution ->

Gives TLE of course ->

The TC for this solution is - Exponential..

int solve(int i, int j, int arr[]) {
        if (i == j) return 0;
        
        // the below condition is not reqd - it will be solved within the partition calculations. but u can still have it
        //no harm

        // if (i + 1 == j) { //only one way to multiply these guys so lets do this
        //     return arr[i-1] * arr[i] * arr[j];
        // }

        //make a partition at k - (i, k) and (k+1, j) - so k goes from i to j-1
        int mini = INT_MAX;
        for(int k=i; k<=j-1; k++) {
            //first the two partitions get solved 
            int partition1 = solve(i, k, arr);
            int partition2 = solve(k+1, j, arr);
            
            //now multiplying these partitions will also require some operations
            int multiplyPartitions = arr[i-1] * arr[k] * arr[j];
            mini = min(mini, partition1 + partition2 + multiplyPartitions);
        }
        return mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        return solve(1, N-1, arr);
    }


Memoizing this solution ->

    int solve(int i, int j, int arr[], vector<vector<int>>& dp) {
        if (i == j) return dp[i][j] = 0;
        
        // if (i + 1 == j) { //only one way to multiply these guys so lets do this
        //     return dp[i][j] = arr[i-1] * arr[i] * arr[j];
        // }
        
        if (dp[i][j] != -1) return dp[i][j];
        
        //make a partition at k - (i, k) and (k+1, j) - so k goes from i to j-1
        int mini = INT_MAX;
        for(int k=i; k<=j-1; k++) {
            //first the two partitions get solved 
            int partition1 = solve(i, k, arr, dp);
            int partition2 = solve(k+1, j, arr, dp);
            
            //now multiplying these partitions will also require some operations
            int multiplyPartitions = arr[i-1] * arr[k] * arr[j];
            mini = min(mini, partition1 + partition2 + multiplyPartitions);
        }
        return dp[i][j] = mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return solve(1, N-1, arr, dp);
    }

Easy memoization!

We can also do Tabulation for this to save more space ->

TABULATION ->

Focus on how the j goes. Dont just directly reverse the j here .

int matrixMultiplication(int N, int arr[])
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    // return solve(1, N-1, arr, dp);
    
    //base case
    for (int i=0;i<N;i++) {
            dp[i][i] = 0;
    }
    
    for (int i=N-1; i>=1; i--) {
        for (int j=i+1; j<N; j++) { //start from the right of i. dont just directly reverse the order for tabulation
            int mini = INT_MAX;
            for (int k=i; k<j; k++) {
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                mini = min (steps, mini);
            }
            dp[i][j] = mini;
        }
        
    }
    return dp[1][N-1];
}

