Merge 2 sorted arrays


Easy approach - brute force - just keep two pointers, one on each array and add elements accordingly to a new Third array.

Time - O(n+m)
Space - O(n+m)

But optimal solution would be to do it with no extra space. 

OPTIMAL SOLUTION 1 ->

Approach - again 2 pointers 

But if you have two sorted arrays -

A - 2 5 6
B - 1 3 5

Intuition for constant space completxity approach -
You can compare the last ele of A and first ele of B and make a decision on whether to swap or not.

After each swapping step - move to one position left in A and one position right in B

If you find that the left pointer is already less than the right pointer - break and stop the process.

At the end of this - you will see that A has all the elements which the first A.size() elements of sorted combination array should have
and similar for B

sort(A) and sort(B) and combination is the answer basically.

Watch striver video for the above solution - https://www.youtube.com/watch?v=n7uwj04E0I4&ab_channel=takeUforward


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = 0;

        while (i >=0 && j<n) {
            if (nums1[i] > nums2[j]) {
                swap(nums1[i], nums2[j]);
                i--;
                j++;
            }
            else break;
        }

        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.begin() + n);

        //copy nums2 into nums1 ka remaining part;
        for (int y=0, x=m; y<n; y++) {
            nums1[x] = nums2[y];
            x++;
        }
    }
};


OPTIMAL SOLUTION 2 ->

GAP METHOD - intuition comes from Shell Sort

This is also a 2 pointer algorithm. Learn, mug, do whatever with it.



