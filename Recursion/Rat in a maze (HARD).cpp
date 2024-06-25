My code -

Ran in the first go

Note - we have not sorted here because - we did D (down) , L , R and U in order (in the recursive function)

If we did any other order - we will have to explcitily sort(ans.begin(), ans.end()) in the main function..

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> ans;
        string temp;
        solve(ans, temp, m, n, 0, 0);
        
        return ans;
    }
    
    void solve(vector<string> &ans, string temp, vector<vector<int>> &m, int n, int i, int j) {
        
        if (m[i][j] == 0) {
            return;
        }
        
        if (i == n-1 && j == n-1){
            ans.push_back(temp);
            return;
        }
        
        //try to go in all directions
        //make sure to mark the current position (which you're about to leave from) 0 - 
        //because it is stated that we cannot visit a cell twice.
        
        //Down
        if (i+1 < n) {
            temp.push_back('D');
            m[i][j] = 0;
            
            solve(ans, temp, m, n, i+1, j);
            
            //backtrack
            temp.pop_back();
            m[i][j] = 1;
        }
        
        //Left
        if (j-1 >= 0) {
            temp.push_back('L');
            m[i][j] = 0;
            
            solve(ans, temp, m, n, i, j-1);
            
            //backtrack
            temp.pop_back();
            m[i][j] = 1;
        }
        
        //Right
        if (j+1 < n) {
            temp.push_back('R');
            m[i][j] = 0;
            
            solve(ans, temp, m, n, i, j+1);
            
            //backtrack
            temp.pop_back();
            m[i][j] = 1;
        }
        
        //Up
        if (i-1 >= 0) {
            temp.push_back('U');
            m[i][j] = 0;
            
            solve(ans, temp, m, n, i-1, j);
            
            //backtrack
            temp.pop_back();
            m[i][j] = 1;
        }
        
        
        
        
        
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends