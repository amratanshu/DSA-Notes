Did it completely by myself yay

1. Find the pivot point first using b search
2. perform binary search in the two sorted partitions around mid easily

Note - handle for no pivot found edge case also

Consider 4 5 6 7 0 1 2

mid is 7

u can see that high (2) is less than mid

So the pivot has to be in the right thing

Just include the mid in the right partition too - as mid can also be a pivot (in this case - it definitely is)



class Solution {
public:
    int search(vector<int>& nums, int target) {
        //find the pivot using binary search first

        int low = 0;
        int high = nums.size() - 1;

        int pivot;
        while(low < high) {
            int mid = low + (high - low)/2;

            //base case for loop (terminate here)
            if (high == low + 1) { //only 2 elements in this partition
                pivot = low;
                break;
            }
            
            
            //compare low, mid and high
            if (nums[mid] > nums[high]) {
                //pivot is somewhere on the right side
                //note: when partitioning - include mid too

                low = mid;
            }

            else if (nums[mid] < nums[low]) {
                //pivot is somewhere on the left side
                //note: when partitioning - include mid too

                high = mid;
            }

            else { //no pivot found - it seems to be in correct order
                pivot = -1;
                break;
            }
        }

        //divide the arrays into two sorted arrays
        if (pivot == -1) //no pivot
        {
            return binarySearch(0, nums.size()-1, nums, target);
        }
        int ans1 = binarySearch(0, pivot, nums, target);
        int ans2 = binarySearch(pivot+1, nums.size()-1, nums, target);

        if (ans1 == -1 && ans2 == -1)
            return -1;
        
        if (ans1 == -1 && ans2!=-1)
            return ans2;

        if (ans1 !=-1 && ans2 == -1)
            return ans1;

        return -1; //will never happen ideally
    }

    int binarySearch(int low, int high, vector<int> nums, int target) {
        while(low<=high) {
            int mid = low + (high - low)/2;

            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target) {
                high = mid - 1;
            }
            if (nums[mid] < target) {
                low = mid + 1;
            }
        }
        return -1;
    }
};