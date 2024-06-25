The idea is that for a number to be median there should be exactly (n/2) numbers that are less than this number. So, we try to find the count of numbers less than the selected number. We select the number by using binary search.

Implementation
Step 1: find the minimum and maximum present in the matrix, which will be used as range of binary search.
Step 2: run a loop while min num is less than max num
inside the loop
   Step 3: find mid position, mid = min num + (max num – min num) / 2;
   Step 4: now for each row, count how many numbers are less than mid,
   Step 5: if count is less than half of the number update min num = mid +1
               else max num = mid
loop end
return min.



Solution I wrote - was a little messy because everything is done manually

(there is editorial solution also pasted below my solution)

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i=0;i<R;i++) {
            for (int j=0;j<C;j++) {
                if (matrix[i][j] > maxi)
                    maxi = matrix[i][j];
                
                if (matrix[i][j] < mini)
                    mini = matrix[i][j];
            }
        }
        
        int low = mini, high = maxi;
        
        while (low <= high) {
            int mid = low + (high - low)/2;
            int nBy2 = (R*C + 1)/2;
            
            int x = numbersLessThan(mid, matrix, R, C);
            
            if (x < nBy2)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low;
    }
    
    //find out numbers which are less than mid
    int numbersLessThan(int mid, vector<vector<int>> matrix, int R, int C) {
        int count = 0;
        for(int i=0;i<R;i++) {
            for (int j=0;j<C;j++) {
                if (matrix[i][j] <= mid)
                    count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends





Solution copied from GFG editorial ->

Note - See how they are calulating the number of elements which are less than mid --

Use things like the upper_bound method to save a lot of time

//Back-end complete function template for C++

class Solution {

public:
    //Function to find the median of a matrix.
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        //Initializing the minimum and maximum values.
        int min = INT_MAX, max = INT_MIN;
        
        //Iterating through each row of the matrix.
        for (int i = 0; i < R; i++)
        {
            //Updating the minimum value if current element is smaller.
            if (matrix[i][0] < min)
                min = matrix[i][0];
     
            //Updating the maximum value if current element is bigger.
            if (matrix[i][C-1] > max)
                max = matrix[i][C-1];
        }
     
        //Calculating the desired position of the median.
        int desired = (R * C + 1) / 2;
        
        //Using binary search to find the median value.
        while (min < max)
        {
            //Calculating the middle value.
            int mid = min + (max - min) / 2;
            
            //Counting the number of elements in the matrix that are less than mid.
            int place = 0;
            for (int i = 0; i < R; ++i)
                place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            
            //Updating the search range based on the count.
            if (place < desired)
                min = mid + 1;
            else
                max = mid;
        }
        
        //Returning the median value.
        return min;
    }
};
