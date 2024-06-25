https://leetcode.com/problems/3sum/description/

Brute force is N^3 - find i j k - and run loop for all three
For i 0 to n, run j = i+1 to n, and run k = j+1 to n


Better solution is near N^2 (N^2 logn to be precise) -

Use two loops for i and j - but for the 3rd element - use a hashmap to find (target - arri - arrj)

But here - make sure that the third element should not be one of arr[i] and arr[j] - because we need all three
distinct elements in the ans

To solve this - in the hashmap, just hash the numbers BETWEEN  arr[i] and arr[j] in the array

This way - when i=0 and j=n-1 -> you will have covered all the possibilities of a third number in bw

Then i++, and try to cover the possibilities iterating j from 2 to n-1 again

Remember here - just before doing j++ -> put the element in the hashmap so that it is counted now

When you do i++ -> empty the hashmap because now we want to consider a completely new set

Doing this - you will run into many duplicate triplet sets - e.g we dont want [0 1 -1] and [0 -1 1] both in the answer

So use a Set of vector<int> data structure to store the sorted triplets.


TC - N^2 logn - --- #logn is from the hashset.find method calls
SC - O(n) - for storing max no of elements in the hashset + O(no of unique triplets * 2) - for storing the answer

But this solutions space complexity can be further optimised

We can optimise further to reduce the space used by the unique triplets

BEST SOLUTION - get rid of this external data structure which is storing the answer after sorting a triplet each time

Instead - 
1. sort the array
2. Use two pointer approach - similar to what can be used in the 2sum problem


Approach - 
SORT FIRST

Keep i fixed, move j and k acc to sum bigger or smaller.

i j k is our triplet.

We need to find distinct triplets which sum up to zero or k..

fix i, j = i+1 and k = end of the array

If i + j + k < target -> j++; else if (<target) do k--;

if equal - include them in the answer

But one catch -> if the array if --> -1 -1 -1 0 0 2 2 2 

Lets say [-1 -1 2] has been counted in the answer already

So next time - while moving k -> we dont want to count 2...so just move it back till 0 (till not 2) 

Similarly - while moving j -> we dont want to count -1 again ... move it till 0..

Striver video better explanation ->

Keep moving till j and k do not cross each other. i j k must be in that order (sorted triplets)



TIME COMPLEX -

nlogn to sort it

external n (for) loop (i wala)

Internal While loop (j and k wala) -> n-1 times, then agli bar n-2 times....so on

TIME complexity total --> n logn + n^2

Space complexity -> O(no of unique triplets) + O(constant) - constant comes from the vector which stores the answer
but it is minimal and we can even ignore it.



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int low = i + 1;
            int high = n - 1;
            int sum = 0;
            while (low < high) {
                sum = nums[i] + nums[low] + nums[high];
                if (sum < 0) {
                    low++;
                } else if (sum > 0) {
                    high--;
                } else {
                    vector<int> temp = {nums[i], nums[low], nums[high]};
                    ans.push_back(temp);
                    int last_high = nums[high];
                    int last_low = nums[low];
                    while (nums[low] == last_low && low < high)
                        low++;
                    while (nums[high] == last_high && low < high)
                        high--;
                }
            }
        }
        return ans;
    }
};