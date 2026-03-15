https://leetcode.com/problems/sliding-window-median/description/

This is a Sliding Window problem as well obviously

can brute force easily by using sliding window using a MULTISET.. (that would be O(NK))

Better solution - would be using 2 multisets (one for left smaller array segment, and one for right half which is the bigger array segment of a window)

Assume - the right one can have one more element than the left one, in case there are ODD number of elements in the window. 
(but otherwise always balanced)

So median will be left->last + right->first / 2 OR right->first

Multisets are always ordered as well.

