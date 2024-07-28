https://www.youtube.com/watch?v=mJcZjjKzeqk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=45&ab_channel=takeUforward

Take a priority queue - MIN HEAP -- so use the greater<int> when initializing it
pq -> <wt, node, parent>

Step 1 ->
Insert the first node (can be any node) on to the pq

0, 0, -1 --> first insertion into the pq

Step 2 ->
take the min element out - 
If its unvisited - 
mark them as visited

take the adjacent nodes

put them in the pq


Untimately u will get the MST

Intuition -

We are using a PQ min heap

It is just a greedy algo - at every adjacent - you take the minimum...

------------------------------------------------------------------------------------------------------------
TIME COMPLEX ->

We run a loop on priority queue - which will iterate over all edges in the tree - in the worst case

1. so while loop - E times

2. Inside the while loop - pq.top() will take - log(pq.size())
worst case - log E

3. Another time consuming thing is going through all the edges in the auto adj: adj[] wala loop
Hence - overalll, overall - we will move across all edges - amortized wala logic

So - that is also ELogE !

Hence total => ELog(E) + ELog(E) 

hence overall also - E Log(E) 

------------------------------------------------------------------------------------------------------------
SPACE COMPLEX ->
Pq can take max of O(E)
