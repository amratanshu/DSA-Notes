https://leetcode.com/problems/arithmetic-slices/description/?envType=company&envId=google&favoriteSlug=google-three-months

Example -> 
1 3 5 7 8 9 10 11 12 13 18 21

I think we will find out the answer if we knew what the longest streaks of ARITHM were.

In this case - 
DIFF 2 STREAK is 4
Diff 1 STREAK is 7

For each streak of more than 3 numbers -> no of subarrays is SUM OF NATURAL NOS TILL <StreakCount - 2>

For streak of 7 -> 

No of subarrays of len 7 -> 1
No of subarrays of len 6 -> 2
No of subarrays of len 5 -> 3
No of subarrays of len 4 -> 4
No of subarrays of len 3 -> 5

My thought - take two pointers -> keep first one fixed and start calculating
As soon as u find an anomaly in the differences - 


This was the mathematical solution I think.

There is another DP solution that exists as well!

DIVIDE AND CONQUER - Think!
We make an dp array (we say it as t), and then we starting storing result, by saying that,
Upto this point, how many number of subarrays are their, with a given difference.
If the current difference is same as the previous diffference, then we say, all the previous arrays 
are also applicable with this current element, so we increase our dp[i] as d[i] = dp[i -1] + 1

Just solve on paper - and u will understand why we need to do and = ans + dp[i]

this is also basically calculating streaks of some diff - Same stuff which I was doing earlier!!
BECAUSE dp[i] is set to Zero immediately when new diff is found

EASY PEASY

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size(); // extracting the size of the array
        
        if(n < 3)  // if size is less than 3
        {
            return 0; // then simply return 0
        }
        
        int ans = 0, curr = 0; // declaring variables
        
        // for the first part
        // it stores what is the difference of last consecutive elements
        int last_diff = arr[1] - arr[0];
        
        // start traversing from the array
        for(int i = 1; i < n - 1; i++)
        {
            // for any index what is the current difference
            int curr_diff = arr[i + 1] - arr[i];
            
            // if current difference is equal to the last difference
            if(curr_diff == last_diff)
            {
                curr++; // increase current variable
            }
            else // but if not, give current difference to last difference
            {
                last_diff = curr_diff;
                curr = 0; // and make curr to zero, as we have to do a new start
            }
            
            ans = ans + curr; // add current to our answer
        }
        
        return ans; // finally return the answer
    }
};