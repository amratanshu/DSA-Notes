Ques - https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings

Approach ->
https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/solutions/766485/kosaraju-algorithm-on/

https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/solutions/3690092/using-graph-scc-kosaraju-s-algorithm/


Model this question as graph problem

uses SCC concept - present in adjacent files ->

If there is a character 'b' between the first and last occurrence of character 'a', then it means we 
must include 'b' in the substring if we want to include 'a', so we can create an edge from 'a' to 'b'.

So we can convert the input string into a directed graph, which has at most 26 vertex 'a' to 'z'.

Within this graph, each SCC (Strongly Connected Components) much be included in a substring together. 
Additionaly, 'downstream' SCCs of a chosen SCC must also be included in the same substring.

Thus, its easy to see that we just need to find all the SCC with 0 out-degree. Characters in each SCC 
are characters we must include in each substring. And it is guaranteed to be minimal total length.

In the example =>

a d e f a d d a c c c

The graph - 

Edges - 
a to d
d to a
a to f
d to f
a to e
d to e
c loner

Basically - a depends on d - because if we want to choose a - we must choose d

and a depends on f - if we want to choose a - we must choose f

The nodes wotwith outdegree = 0 - do not depend on anyone. They can be taken in as the smallest substrings which satisfy our conditions

Graph solution with comments ->
https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/solutions/5462155/kosaraju-s-algorithm-scc-c-complete-solution-with-comments/


Another solution but not using this Graph Algorithm ->
https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/solutions/5373887/kosaraju-s-algorithm-approach/

Approach ->
First, we store the first and last index of each character in a map.
Then traverse the map and for each character , traverse the string from its left and 
right index to find the valid intervals and taking that all the occurences of each character 
should be present in a substring.
Traverse the valid intervals and storing the substrings which are not overlapping.
In the end, return the result.