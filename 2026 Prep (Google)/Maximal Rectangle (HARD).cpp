https://leetcode.com/problems/maximal-rectangle/

Maximal Square was easier.

Rectangle is slightly trickier.

First thought - somehow can we store the maximum streak of 1s (vertical streak AND horizontal streak)
ending at i, j --??

Would this help? (imagine traversing the 2D matrix in right down fashion like we usually do)

But here - how to form the recurrence relation using the i-1, j-1 element?



