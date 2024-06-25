https://leetcode.com/problems/majority-element-ii/

https://www.youtube.com/watch?v=vwZj1K0e9U8&ab_channel=takeUforward

Logic - same as Boyer Moore

Cancellation logic - if any element other than ans comes - we decrease the counter by 1

Here - caveat - we can have maximum 2 integers in our answer 

Because - there can only be 2 integers in the array which can appear more than n/3 times.
Eg - in an array of 8 eles, there can be either 1 number which appears more than 2 times (3 and more)
or there can be 2 numbers which appears more than 2 times.

There cant be 3 numbers which appear more than 2 times - because n is 8 only. (this would cause n to be 9 min)

Hence - in this application of boyer moore - we assume 2 numbers in our answer - 

and maintain 2 counters.

ele 1           ele 2
count 1         count 2

and apply the same cancellation logic which we did in the previous majority element question

But wait - it is not that simple!

Doing just this directly wont work

Example - [ 2 1 1 3 1 4 5 6]

When we are at 3 - by our logic - it will cancel one 1 and one 2.

Then next - when we are at 1 (next element) - counter1 is zero so this will get increased to 1 and element1 will be assigned "1".

but this is wrong because - element 2 is already holding "1"

So add a check for this as well

And ! In the end - add a manual check in the end to make sure that these 2 elements are actually the majority elements
in this array or not.

class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size(); // arr size

        int cnt1 = 0, cnt2 = 0; // counts
        int el1 = INT_MIN;      // ele 1
        int el2 = INT_MIN;      // ele2

        // applying extended boyer voting algo
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && el2 != v[i]) {
                cnt1 = 1;
                el1 = v[i];
            } else if (cnt2 == 0 && el1 != v[i]) {
                cnt2 = 1;
                el2 = v[i];
            } else if (v[i] == el1) {
                cnt1++;
            } else if (v[i] == el2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ls; // list of answers

        // manually checking
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == el1) {
                cnt1++;
            } else if (v[i] == el2) {
                cnt2++;
            }
        }

        int mini = int(n / 3) + 1;
        if (cnt1 >= mini) {
            ls.push_back(el1);
        }
        if (cnt2 >= mini) {
            ls.push_back(el2);
        }
        // sort(ls.begin(),ls.end());
        return ls;
    }
};