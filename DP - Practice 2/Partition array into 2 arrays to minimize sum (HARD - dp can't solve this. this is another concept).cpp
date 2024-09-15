https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

This question is

MEET IN THE MIDDLE.

Leetcode solutions tend to be using binary search also for this... It is the better solution apparently. 

but anyway for now - dp approach - we'll try to find if there is a subset with sum = total/2.. then find sum - 1... etc.. 
so that absolute difference is minimized

See striver video

UNDERSTAND what each cell in the DP tabulation for the subset sum problem say.

Every cell says true or false for each index and target combination. Ok? Understand this.

NOTE - this tabulation solution only works on positive numbers. leetcode wale question
me Negative numbers bhi allowed and usme kuch aur jugaad karna padta hai - maybe using long long or something?

Another question - how are we making sure that each subset has exactly n items? strivers solution might be wrong for the
exact question on leetcode.


yeah i was right - DP cant solve this.

We can even solve the negative numbers but the partition into exact n items - dp cant do that.

https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/solutions/2786039/dp-handling-cases-when-sum-is-negative-c/

