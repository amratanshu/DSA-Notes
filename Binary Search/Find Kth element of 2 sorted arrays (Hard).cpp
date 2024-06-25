Hard because follows the logic of median of 2 sorted arrays question

By doing binary search - in both these questions - 
binary search is helping us search for HOW MANY numbers to take from ARR1 into my Left half.

Read this line again.

Otherwise intuition for this approach is difficult

So - we can take lowest 0 numbers from ARR 1 to form left partition 
And max we can take all items in ARR1

So it becomes a binary search kind of thing where 
low = 0
high = arr1.size() 

This high here - does not mean index !!

Hence we didnt initialize high to arr1.size() - 1 

Almost same code as MEDIAN of 2 SORTED ARRAYS

Just pay attention to how low and high is being assigned here --

Minimum elements u can pick from ARR1 - is max(0, k-m) because if ARR1 has lesser than K members - we have to pick all

Maximum elements u can pick from ARR2 - is min(k, n) because say - we pick all in ARR1 (say, 5) and k is 10 but ARR2 doesnt have 
5 elements. So in this case - partition cant happen

..

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {  
        //if n1 is bigger swap the arrays:
        if (n > m) return kthElement(arr2, arr1, m, n, k);
        
        // int left = (n + m + 1) / 2; //length of left half
        int left = k;
        
        
        //logic for assigning low and high - how many elements can u pick from arr1 into the left partition
        //minimum and maximum .. see video to know more
        int low = max(0, k-m), high = min(k, n); 
        
        while (low <= high) {
            int cut1 = (low + high) >> 1; //half karne ka fancy method
            int cut2 = left - cut1;
            
            //calculate l1, l2, r1 and r2;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            
            //only if these conditions are true, r1 and r2 and l1 and l2 exist
            if (cut1 != 0) l1 = arr1[cut1-1]; 
            if (cut2 != 0) l2 = arr2[cut2-1];
            
            if (cut1 != n) r1 = arr1[cut1];
            if (cut2 != m) r2 = arr2[cut2];
    
            if (l1 <= r2 && l2 <= r1) {
                //we have properly sorted array here - proper partition found
                return max(l1, l2);
            }
    
            //eliminate the halves:
            else if (l1 > r2) high = cut1 - 1;
            else low = cut1 + 1;
        }
        
        return 1; //dummy statement
        
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends
