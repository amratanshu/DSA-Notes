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

Similarly - if we reverse the edges of 3->4, 4->7, 6->7 - and we run dfs on each of the nodes - 

we can print the individual SSC's

But how will we know which edges to reverse? yeah we dont. So just reverse all the edges

Also - after doing this - we want to print the SSCs in order.

So for that - after reversing - we also need to know whether to run dfs on 0 first or 2 first or 7 first...

This makes our algorithm !!

1. Do a dfs and store all the elements in the dfs in the stack - this way when u take it out - the elements 
will be in the order of the time_frame it took to print them - basically sorted oppositely

2. Reverse all the nodes in the graph

3. Now start popping from the stack and start doing dfs on it - if this is not visited yet