Great concept!

See the screenshot first

What is Strongly Connected Component?
A component where - from one node - the entire component can be visited

ss 1->
We see that - 0, 1, 2 - we can start from any node in these 3 and we can visit the other 2

But (3) is not in this strongly connect component -
- we can go to 3
- but we cannot come back from 3 ever

In this graph - we can intuitively see that - 
If I run a dfs from node 0 - it will go to the innert most node - node 7

First SCC - wala dfs - reaches node 3.

We dont want that. We just want it to cycle in those 3 nodes - 0 1 2 

Haina? so what if we reverse the edge from 3 - that way - we block it going from 2 to 3

