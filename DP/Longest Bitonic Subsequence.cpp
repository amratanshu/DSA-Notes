https://www.codingninjas.com/studio/problems/longest-bitonic-sequence_1062688?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=3

multiple approaches - 

1. come to mind first : 3D DP - keep f(index, prev, increasing)

So adding on to LIS we've kept a variable for determining increasing or decreasing and 
we can form our recurrence relation on the basis of that simply.

2. Find the longest increasing subsequence 
Do LIS only
Create 2 single DP's    '

Run first loop i = 0 to n-1 and pre = 0 to i-1
to calculation max increasing subsequence length from Left 

Run second loop from i = n-1 to 0 AND prev = n-1 to i+1 (decreasing loop, i-- and prev--)
to calculate the LIS from right

Find a point where length of LIS is max from left and right

This solution is good if the grader can accept strictly increasing or decreasing susbequences as well !

int longestBitonicSubsequence(vector<int>& arr, int n) {	
	vector<int>dp1(n, 1), dp2(n, 1);
	// find LIS from left
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && dp1[i] < dp1[j] + 1){
                dp1[i] = dp1[j] + 1;
            }
        }
    }   

	// find LIS from right
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(arr[i] > arr[j] && dp2[i] < dp2[j] + 1){
                dp2[i] = dp2[j] + 1;
            }
        }
    }   
	
    // find a point from where length of LIS is max from left and right
    int maxi = 0;
    for(int i=0; i<n; i++){
        maxi = max(maxi, (dp1[i] + dp2[i] - 1));
    }
    return maxi;	
}

This solution is giving wrong on GFG - because of test cases like ->

ARR - 5 7 9

Our code output - 3
Correct output - 0

Why is this issue arising?? -

because we are also considering the max from cases where dp1[] or dp2[] = 1

if one of either dp arrays is 1 - opposite wala LIS combine karke bhi we'll form a strictly increasing subsequence

Hence - check for this

Do a dry run for 5 7 9 and you will understand

So - to resolve this - just add the condition ->

for(int i=0; i<n; i++){
            if (dp1[i] != 1 && dp2[i] != 1)
                maxi = max(maxi, (dp1[i] + dp2[i] - 1));
        }
        return maxi;

FINAL SOLUTION ->

int LongestBitonicSequence(int n, vector<int> &arr) {
        vector<int>dp1(n, 1), dp2(n, 1);
    	// find LIS from left
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i] > arr[j] && dp1[i] < dp1[j] + 1){
                    dp1[i] = dp1[j] + 1;
                }
            }
        }   
    
    	// find LIS from right
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>i; j--){
                if(arr[i] > arr[j] && dp2[i] < dp2[j] + 1){
                    dp2[i] = dp2[j] + 1;
                }
            }
        }   
    	
        // find a point from where length of LIS is max from left and right
        int maxi = 0;
        
        for(int i=0; i<n; i++){
            if (dp1[i] != 1 && dp2[i] != 1)
                maxi = max(maxi, (dp1[i] + dp2[i] - 1));
        }
        return maxi;
    }
