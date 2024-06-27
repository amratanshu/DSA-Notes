This question is a HARD DP Question as well - check out solution in DP folder

https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/hints/

APPROACH ->

Each index of LPS array contains the longest prefix which is also a suffix. 
Now take the string and reverse of a string and combine them with a sentinal character in between 
them and compute the LPS array of this combined string. Now take the last value of the LPS array and 
subtract it with the length of the original string, This will give us the minimum number of insertions 
required in the begining of the string .

