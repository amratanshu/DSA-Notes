Easy concept 

maximise on the value/weight ratio and start taking one by one;.

Hence, Sorting is required

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    static bool comparator(Item a, Item b) {
        double r1 = (double) a.value/a.weight;
        double r2 = (double) b.value/b.weight;
        
        if (r1>r2)
            return true;
        else return false;
    }
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        
        sort(arr, arr+n, comparator);
        
        double profit = 0;
        
        //store until bag is full
        int remainingW = w;
        
        for (int i=0;i<n;i++) {
            //if we can put it full
            if (arr[i].weight <= remainingW) {
                remainingW -= arr[i].weight;
                profit += arr[i].value;
            }
            
            else { //take fractionally
                profit += (double)arr[i].value/arr[i].weight * remainingW;
                return profit;
            }
        }
        
        return profit;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends