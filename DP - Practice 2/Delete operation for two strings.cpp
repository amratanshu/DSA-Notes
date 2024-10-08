https://leetcode.com/problems/delete-operation-for-two-strings/

EDIT DISTANCE but with only DELETE operation allowed.

easy - just find the longest common subsequence 
and then do - 

return (word1.size()-lcs) + word2.size()-lcs
