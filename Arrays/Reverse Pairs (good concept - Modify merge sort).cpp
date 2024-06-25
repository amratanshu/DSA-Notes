https://leetcode.com/problems/reverse-pairs/

Good question - 

Very similar to Count inversions 

Same concept

Comments in the code - will help u understand.

Dont forget to handle the integer overflow due to multiplication with 2 !

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int count = 0;
        mergeSort(nums, 0, n - 1, count);
        return count;
    }

    void merge(vector<int>& arr, int low, int mid, int high, int& count) {
        vector<int> temp;    // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1; // starting index of right half of arr
        // storing elements in the temporary array in a sorted manner//

        //run an extra auxilliary loop here to count the reverse pairs - it can't be done within the merge function of merge sort.
        //do a dry run to understand why - take example of merging [2 3 4] and [1 5] - we will do right ++ and put 1 in the temp. so that wont be counted in the answer.
        int i = low;
        int j = mid + 1;
        while (i<=mid && j<=high) {
            //this below line wont work because multiplying by 2 can cause the integer to overflow. 
            //Handle it carefully using long long. Logic is same only.
            // if (arr[i] > 2*arr[j]) {

            if ((long long)arr[i] > (long long)2 * (long long)arr[j]) {
                
                count += mid - i + 1;
                j++;
                
            }
            else 
                i++;
        }


        //standard while loop for merging ->
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left //
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int>& arr, int low, int high, int& count) {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid, count);      // left half
        mergeSort(arr, mid + 1, high, count); // right half
        merge(arr, low, mid, high, count);    // merging sorted halves
    }
};