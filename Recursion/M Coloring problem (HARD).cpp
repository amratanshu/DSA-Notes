My own solution

Watch striver video for more understanding (just the explanation part) - he did exact same solution as mine.

But Otherwise - comments of this code are understandable




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        
        vector<int> colored(n, -1);
        return solve(0, colored, graph, m, n);
    }
    
    
    //logic - 
    //try coloring each idnex (one by one in order) and try giving them all colors from 1 to m
    bool solve(int index, vector<int> &colored, bool graph[101][101], int m, int n) {
    
        
        if (index == n) {
            return true;
        }
        
        for (int i=0;i<m;i++) {
            
            //what if already colored?
            
            
            bool canColor = true;
            //check the adjacent nodes now 
            
            for (int j=0; j<n; j++) {
                if (index == j) continue;
                if (graph[index][j]) { //means a node
                    if (colored[j] == i) //same color
                    {
                        canColor = false;
                        break;
                    }
                } 
            }
            
            if (canColor == true) {
                colored[index] = i;
                if (solve(index+1, colored, graph, m, n))
                    return true;
                colored[index] = -1;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends