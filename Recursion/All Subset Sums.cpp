Easy question

take the remaining array into account

https://www.geeksforgeeks.org/problems/subset-sums2234/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        
        vector<int> result;
        
        int index = 0;
        int sum = 0;
        solve(result, arr, index, sum);
        return result;
    }
    
    vector<int> solve(vector<int> &result, vector<int> &arr, int index, int sum) {
        if (index == arr.size()) {
            result.push_back(sum); //nothing left to be added
            return result;
        }
        
        solve(result, arr, index+1, sum + arr[index]); //pick this element into the sum
        solve(result, arr, index+1, sum); //dont pick this element into the sum
        return result;
    }
        
    
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends