https://leetcode.com/problems/majority-element/description/

https://www.youtube.com/watch?v=nP_ns3uSh80&ab_channel=takeUforward


1. Apply Moore's voting algorithm - watch video of this to quickly learn it
2. If we get some element as majority - it may or may not be a majority in the whole array. - so count the frequency of 
this element to be sure. Otherwise there is no majority element.


But if in the question - 
It says that there must be a majority element in the given array - then we can safely assume that the winCandidate is out answer.
Code ->

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winCandidate = nums[0], size = nums.size(), candVotes = 0;
        for(int num : nums){
            if(num == winCandidate)
                candVotes++;
            else{
                candVotes--;
                if(candVotes == 0){
                    candVotes = 1;
                    winCandidate = num;
                }
           }
        }

        //to re verify
        int count = 0;
        for (int num : nums) {
            if (num == winCandidate) {
                count ++;
                if (count == size/2)
                    return winCandidate;
            }
        }
        return -1;
    }
};