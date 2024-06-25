https://www.interviewbit.com/problems/allocate-books/

https://www.youtube.com/watch?v=gYmWHvRHu-s&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=70&ab_channel=takeUforward

Difficult to understand

Look at the video quickly, you will remember

Important question!! asked in many interviews of big companies like Google and Flipkart

Comments are explanatory

bool isPossible(int barrier, vector<int> &A, int B) {
    //see if you can keep maxSum of a partition under barrier given B students. 
    //As soon as u need more students, return false
    int countStudents = 1;
    int maxPages = 0;
    for(int i=0;i<A.size();i++) {
        if (A[i] > barrier)
            return false;
        if (maxPages + A[i] > barrier) {
            countStudents ++;
            maxPages = A[i];
            if (countStudents > B)
                return false;          
        }
        else {
            maxPages += A[i];
        }
    }  
    return true;
}

int Solution::books(vector<int> &A, int B) {
    //the maximum pages in a partition (in a singel configuration) 
    //can range from max element in array (low - single ele in partition) to sum of all elements in A (high)
    //we have to find this max pages such that it is lowest
    //hence we are doing binary search on it
    
    if (B > A.size()) 
        return -1;

    int result = -1;
    
    int low = *max_element(A.begin(), A.end());
    
    int high = 0;
    for (auto i: A) {
        high += i;
    }
    
    // fancy way to sum all elements -> int high = accumulate(arr.begin(), arr.end(), 0);
    
    while(low<=high) {
        int mid = (high + low) / 2;
        
        //now we have to check if mid is a possible maximum
        //if it is not - that means - we are unable to fit it within B students - 
        //so we need to search in righ half
        if (!isPossible(mid, A, B)) {
            
            low = mid + 1;
        }
        
        //if such allocation is possible - means this mid can be one answer - but there exists a sum 
        //lesser than this - which might also accomodate these many number of pages
        //x hai toh x se zyada wale toh sare true hi hain obviously
        
        else {
            result = mid; //result will keep on decreasing until a minimum
            high = mid - 1;
        }
    }
    
    return result;   
}