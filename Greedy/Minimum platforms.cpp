

First personal try -

I dont know why this code is not working - but just saving for the approach


1. sort based on departure times
2. assume just one platform and mark its limit (first train ke departure time tak this platform is booked)
3. start traversing and checking if the train can be arrived on the same platform
4. if not, add a new platform
5. at every step - check all the existing platforms and accomodate a train anywhere. if not, add a new platform
6. repeat

This below code is not working

Check striver video and code after this - is code ke bhi neeche


//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	
    	//sort on departure times
    	//maintain another vector for keeping the times until which a platform is busy. Assume only one platform in the beg
    	//keep adding if you need more
    	
        vector<pair<int,int>> time;  
        
        for (int i=0;i<n;i++) {
            time.push_back({dep[i], arr[i]}); //have kept dep first because we want to sort on that
        }
        
        // for(auto p : time) {
        //     cout<<p.first<<endl;
        //     cout<<p.second<<endl<<endl;
        // }
        
        sort(time.begin(), time.end()); 

        vector<int> platformLatest;
        platformLatest.push_back(time[0].first);
        
        
        
        
        for (int i=1;i<n;i++) {
            //check all platforms from the starting where this train can arrive
            int newPlatformNeeded = 1;
            for (int j=0;j<platformLatest.size();j++) {
                if (time[i].second > platformLatest[j]) //can arrive at this station only
                {
                    newPlatformNeeded = 0;
                    platformLatest[j] = time[i].first;
                    break;
                }
            }    
            if (newPlatformNeeded) {
                platformLatest.push_back(time[i].first); //add a new platform
            }
            
        }
        
        return platformLatest.size();
    	
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends







STRIVER ->

Sort start time
Sort end time

Do both these sortings independently

Saari trains ko accomodate toh karna hi hai.

If we check sorted start and ends -

Start - 50 120 200 550 700 850 
End -  500 550 600 700 900 1000

Keep 2 pointers p1 and p2

p1 at index 0 of start
p2 at index 0 of end

Let the first train arrive. maxi = 1 - 1 platform in use right now simultaneously

move p1

Second train - we know - that is arrives at 120. but earliest a train leaves is at 500 - 
so isko toh time lagega boss. We need one more platform - for the 120 train.

So maxi = 2 now - 2 platforms are in use right now simultaneo

Move p1 again

(p2 ab tak move nahi hua hai aage)

next train comes at 200 time. But first train that leaves is at 500, toh tab tak toh rukna hi padega

maxi ++

move p1 again

Now - train is coming at 550 - but the first train is leaving at 500

so 3 platforms me se ek toh khali hi rahega.

no of platforms - dont touch it as it is decreasing. we can occupy

Check the code in striver video


    // Sort arrival and departure arrays
    sort(arr, arr + n);
    sort(dep, dep + n);

    // cnt indicates the current number of platforms needed at a time
    int cnt = 0;
    // maxi indicates the maximum number of platforms needed
    int maxi = 0;

    int i = 0, j = 0;

    // Traverse through all the arrival and departure times
    while (i < n && j < n) {
        // If next event is an arrival, increment count of platforms needed
        if (arr[i] <= dep[j]) {
            cnt++;
            i++;
        }
        // Else, decrement count of platforms needed
        else {
            cnt--;
            j++;
        }
        // Update maxi to the maximum platforms needed so far
        maxi = max(maxi, cnt);
    }

    return maxi;



