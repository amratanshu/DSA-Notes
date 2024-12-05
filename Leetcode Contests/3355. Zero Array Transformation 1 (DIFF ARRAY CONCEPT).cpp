https://leetcode.com/problems/zero-array-transformation-i/

Learn new Concept of Difference Array

https://www.geeksforgeeks.org/difference-array-range-update-query-o1/#

we will simply traverse through range l to r and and subtract -1 from each index for every query and 
if for any index after all queries nums[index]>0 we will return false but it will give tle as tc is O(N*Q)
so we will keep track of indexes for which query is given and store their count in an array for example 
index 5 appears 3 times then array[5]=3
after that if sum of array[index]<nums[index] we will return false as that index didnt
appear required numbber of times.It is also very time consuming so implenting it in efficient manner 
was all about this problem and it can be done using DIFFERENCE ARRAY RANGE UPDATE QUERY IN O(1)

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        //using the concept of difference array RANGE UPDATE!

        int n = nums.size();
        
        vector<int> diff(n+1, 0); //diff arr (all zeroes for all n indexes)

        //basically counting the frequency of say index = 2 -> appearing inside of the queries.

        //so for every query - we have to add 1 for that index (to increase count) in the range of q[0] (l) to q[1] (r), inclusive
        //what we are doing inside this loop - comes from the range update concept
        for (auto q: queries) {
            diff[q[0]] ++;
            diff[q[1] + 1] --;
        }

        //finding the prefix sum of this diff array now - to get the real counts of how many times that "index" was "included" in queries
        vector<int> prefix(n);

        for (int i=0;i<n;i++) {
            if (i == 0) prefix[0] = diff[0];
            else prefix[i] = prefix[i-1] + diff[i];
        }

        //now this prefix array contains how many time that index came in the query windows. 
        //if the value at this index is 4 and it came at least 4 times - that means it can be made zero

        for (int i=0;i<n;i++) {
            if (prefix[i] < nums[i]) return false;
        }

        return true;
           
    }
};
