https://leetcode.com/problems/find-the-duplicate-number/description/


Great approach

New Concept!

We are given an array having n+1 integers and all the elements are in the range of 1 to n (inclusive)

1. Sorting would make the solution easy  nlogn
2. Hashmap/Frequency array would also be a good solution - but space complexity will be linear

We want On time and O1 space.

Whenever we have such an array - and we want to find the duplicate without sorting

Because each element is a number from 1 to n - each elements value can point to another index.

We can create a LinkedList with the values of the elements.

Index - [ 0 1 2 3 4 5 6 7 8 9 ]
Array - [ 2 5 9 6 9 3 8 9 7 1 ]

We can create a LL using values to index pointers - 

LINKED LIST ->

2 -> 9 -> 1 -> 5 -> 3 -> 6 -> 8 -> 7 -> 9

We have created a cycle here.

CONCEPT ->

To find out if we have a cycle - (at least one duplicate) -> TORTOISE AND HARE - 
Fast pointer - moves 2 point
Slow pointer - moves 1 point

If they collide - we have a cycle.

*** If we want to find the point of starting of the cycle ***

Then 
Leave one pointer as it is (at the collision place)
Start the other pointer from the HEAD (2)

Now move both pointers by 1 each. (same speed.)

This way - they will collide at the point where the cycle is starting and that is our duplicate. (9)

Watch striver video for better explanation and proof and pictures

https://www.youtube.com/watch?v=32Ll35mhWg0&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2&ab_channel=takeUforward




class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        //striver linked list approach

        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        //now we are at the cyclic point.

        //Reassign one pointer to head
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

};