https://leetcode.com/problems/longest-consecutive-sequence/description/

https://www.youtube.com/watch?v=oO5uLE7EUlM&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=29&ab_channel=takeUforward

After Brute force and Better (sorting) approach

Optimal approach -

Put all elements of the array in a SET data structure

use unordered_set in C++

Start iterating through the elements in the set

Array - [102, 4, 100, 1, 101, 3, 2, 1, 1] 

When at 102 - if we directly start trying to find 103 then 104 --- it will become like brute force solution only

Instead - at 102 -- try to check if there is 101.
Yes there is - that means - this 102 is not the starting point of a streak.

Now move on..
At 4 - try to check for 3.
There is - so this is also not starting point


Now move on 
At 100 - try to find 99
Not found - means that 100 should be a starting point of a series.
So Now look for 101, found - look for 102 - found. look for 103 -- not found.

So maxCountTillNow = 3;

Now move on
At 1 - try to find 0
Not found - so this is also a starting point
Now look for 2, 3 , 4... 
maxCountTillNow = 4. 

So we have avoided all unneccessary streak traversals

MY Own code - 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();

        unordered_set<int> sett;
        for (int i = 0; i < nums.size(); i++)
            sett.insert(nums[i]);

        unordered_set<int>::iterator itr;
        int count = 1;
        int maxi = 1;
        for (itr = sett.begin(); itr != sett.end(); itr++) {
            count = 1;
            // means current element is the starting element of a streak
            if (sett.find(*itr - 1) == sett.end()) {
                int temp = *itr;
                temp++;
                while(sett.find(temp) != sett.end()){
                    count++;
                    maxi = max(maxi, count);
                    temp++;
                }
            }
            else 
                continue; //current element is not the starting element of a streak
        }

        return maxi;
    }
};