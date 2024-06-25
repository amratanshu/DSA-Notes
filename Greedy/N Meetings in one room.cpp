Concept -

1. We have to sort the meetings on end time
2. If end times are the same - just keep the one coming first in the original array first.
3. One by one - just start picking meetings which END early. Basically traversing this sorted array.

We can do it by using a vector<pair<int,int>>vp ;  


Another way -

Create a struct data structure which can store start, end and position in original array

Create a comparator to sort this struct on end time

Pick one by one and check whens the latest meeting ending.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    struct meeting {
        int start;
        int end;
        int pos; //position of this particular triplet in the original array - if both end times are same - choose the one
        //which comes before in the original array
    };
    
    static bool comparator(struct meeting m1, struct meeting m2) {
        if (m1.end < m2.end)
            return true;
        else if (m1.end > m2.end)
            return false;
    
        else if (m1.pos < m2.pos)
                return true;
        
        else return false;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        if (n==0)
            return 0;
            
        //we have to make a data structure which stores start, end and the index (pos) in the original array
        struct meeting m[n];
        for (int i=0;i<n;i++) {
            m[i].start = start[i];
            m[i].end = end[i];
            m[i].pos = i;
        }
        
        //sort on the basis of end times (and pos, if end time is the same)
        
        sort(m, m+n, comparator);
        
        int ans = 1;
        int limit = m[0].end;
        
        for (int i=1;i<n;i++) {
            if(m[i].start > limit) {
                limit = m[i].end;
                ans++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends