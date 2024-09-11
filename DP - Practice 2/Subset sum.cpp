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