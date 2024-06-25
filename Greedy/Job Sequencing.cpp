

The problem with sorting plainly on one thing and checking is incorrect

Lets say - 

We choose the max profit ones greedily - this is bad because there can be a case where ->

profit      deadline
3           2
4           1
15          10

here 
greedy -> 15 + 3
Bettter -> 4 + 3 + 15


OR 

If we choose the min deadline to maximise just the number of jobs done - is bad.

i.e - we sort using the deadline and then from each deadline - we choose the max profit one.
because 

How do we say whether we must choose a job with this deadline? we cant this way

profit      deadline
1           1
5           1
10          2
10          2

Here
greedy - 5 + 10
Better - 10 + 10

SOLUTION ->

LOGIC is in the comments - read carefully

//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool comparator(Job x, Job y) {
        if (x.profit > y.profit)
            return true;
        return false;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        //first sort using the profits
        
        sort(arr, arr+n, comparator);
        
        //find out who has the maximum deadline so that we can make a slot vector
        int maxi = INT_MIN;
        for (int i=0;i<n;i++) {
            maxi = max(maxi, arr[i].dead);
        }
        vector<int> slot(maxi + 1);
        
        for(int i=0;i<=maxi;i++) {
            slot[i] = -1;
        }
        
        int count = 0;
        int profit = 0;
        
        //traverse the sorted array now
        //GREEDY -> start taking the jobs with the max profit and start filling them in slots towards the end (last deadline possible for this)
        for(int i=0;i<n;i++) {
            for (int j=arr[i].dead;j>0;j--) {
                if (slot[j] == -1) { //do this job here. 
                    slot[j] = 1;
                    profit += arr[i].profit;
                    count++;
                    break;
                }
            }
        }
        
        
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(profit);
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends