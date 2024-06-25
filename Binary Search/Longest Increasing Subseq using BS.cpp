
Not very intuitive but okay - try it.

If arr = [1 7 8 4 5 6 -1 9]

if we start traversing and creating the subsequences one by one -

at 1: 
we have {1}

at 7: we can insert it into the {1}
so we have {1 7}

at 8: we can insert it into the {1 7}
we have {1 7 8}

at 4: we cannot insert it in {1 7 8}, but we can start a fresh one from 1 Rather than 8..
so we have {1 7 8}
            {1 4}

at 5 ->
{1 7 8}
{1 4 5}

at 6 ->
{1 7 8}
{1 4 5 6}

at -1 ->
{1 7 8}
(1 4 5 6)
{-1}

at 9->
{1 7 8 9}
(1 4 5 6 9)
{-1 9}

so the max length LIS is 5.

This way will be very hectic obviously. bad time complexity.listing out all IS's ..'

What we can rather do is:

apart from the main array - we can have just one array - 
but in that, we wont store the exact subsequences.

Rather - in the above example. when we come at element 4. we already have {1 7 8}

We insert 4 to where it belongs by deleing the next index. Basically - 4 belongs just after 1 in the subsq. array
So we can insert it in 7's place and remove 7 totally. (REPLACE)

This will change the array to not have the subsequence at all but it will still maintain the count
and we are just concerned with the COUNT as of now.

Similarly - if element -1's position is very beginning - we insert it in the first positions place 
and delete the first place.

If element 9's place is the last - then we dont have to delete anything - we can just add it there as noone is in that position as of now.

Using binary search - we can find out the position P. 
reiterating - P is the first element after which ele E should be inserted..


Using Binary search - we have to search for the ele (arr[i]) in the subsq array.
If found - then we have to replace the same only. (not change)
If not found, we have to find the index of the first index which is greater thatn ele

in c++
lower_bound function returns us this very same requirement
agar ele is present - returns index of that
else - index of the first index which is greater thatn ele

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> temp;
    temp.push_back(arr[0]);

    for (int i=1; i<n; i++) {
        if (arr[i] > temp.back()) {
            temp.push_back(arr[i]);
        }
        else {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin(); //binary search
            temp[ind] = arr[i]; //just replace
        }
    }

    return temp.size(); //this is the LIS
}
