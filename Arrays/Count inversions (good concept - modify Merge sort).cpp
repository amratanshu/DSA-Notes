
This question is basically merge sort with just one slight modification.

And this is the concept of Fenwick tree - if you wanna read up regarding that later.

Merge sort ke time - while we are merging the right array and the left array - 
we compare the elements 

During each comparison - if the element from the left array is greater than the element from the right array - 
just do countInversions++; 

Intuition behind this - here - merge sort kya karta hai? All it does is shuffle the elements whenever peeche wala is greater than aage wala
in a divide and merge format.

Do a dry run on paper 

Think about the case when merging these 2 arrays -

[5 6 7 8] and [1 2]

When we are iterating the left and right variable - 
And when arr[left] > arr[right] - at that moment - we know that all the remaining elements in the LEFT array - are all bigger than this ele in the right array

so all of them give rise to Inversions!!

Questions Link https://www.naukri.com/code360/problems/count-inversions_615?leftPanelTabValue=SUBMISSION

My code - with only one liner modification to Merge sort algorithm !

#include <bits/stdc++.h> 

void merge(long long *arr, int low, int mid, int high, long long &count) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr
    //storing elements in the temporary array in a sorted manner//
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            

            //MODIFICATION OF MERGE SORT ALGORITHM
            //the number of elements remaining in the left array - are all bigger than the right element
            //and all contribute to the inversions.
            count+= mid - left + 1;

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

void mergeSort(long long *arr, int low, int high, long long &count) {
    if (low >= high) 
        return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid, count);  // left half
    mergeSort(arr, mid + 1, high, count); // right half
    merge(arr, low, mid, high, count);  // merging sorted halves
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    
    int low = 0;
    int high = n-1;
    long long count = 0;
    mergeSort(arr, 0, n-1, count);
    return count;
}