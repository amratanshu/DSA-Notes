https://www.naukri.com/code360/problems/aggressive-cows_1082559

Good question - exact same concept as the last question - Allocate Books

Learn this concept by heart !

Completely wrote this solution on my own

Intuition ->

We have to maximise what? The minimum distance
So we have to do a B Search on the minimum distances possible

low = min(distances between 2 any two stall locations - hence sorted the array and found min(diff))

high = if all cows are put in first and last stall - then min distance would be the highest = stalls[-1] - stalls[0]

Regarding isPossible method ->

It basically checks if this particular minimium distance is possible
How? 
There are k cows
Keep first cow on the first stall

Now if we have to keep minimum distance as mid, 
Then second cow will be at a minimum of 0 + mid

Choose the first number which is greater than or equal to 0 + mid
If this index is x
Now the next cow can be at a minimum of x + mid

So like this - check if you can put all k cows in the given stall locations

If not - return false


#include<bits/stdc++.h>
bool isPossible(int mid, vector<int> stalls, int k) {

    //check if there can be a configuration where mid is the lowest distance between two cows.
    //assume first cow is kept at stalls[0] only - as spread out as possible

    //so the second cow's desiredLocation will be anything greater than stalls[0] + mid
    //search for this desiredLocation again and again...
    int desiredLocation = stalls[0] + mid;
    int cows = 1;
    int i = 1;

    while(i<stalls.size()) {
        if (stalls[i] < desiredLocation) {
            i++;
            continue;
        }
        //next desired location
        cows++;
        if (cows == k) //can fit all cows with MID minimum distance
            return true;
        desiredLocation = stalls[i] + mid;
        i++;

    }
    return false;


}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    //binary search question

    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    
    //minimum distance bw two stalls
    int diff = INT_MAX;
    
    for (int i=1;i<n;i++) {
        if(stalls[i] - stalls[i-1] < diff)
            diff = stalls[i] - stalls[i-1];

    }
    int low = diff;
    int high = stalls[n-1] - stalls[0];

    int result = -1;
    while(low <= high) {
        int mid = low + high;
        mid = mid/2;

        if (isPossible(mid, stalls, k)) {
            //if this min distance is possible - then min distances less than this toh possible honge hi (cram kar do cows ko ek sath)
            //so go to right half of the binary search now
            result = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return result;
}

