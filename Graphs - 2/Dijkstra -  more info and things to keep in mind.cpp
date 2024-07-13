------------------------------------------------------------------------------------------------------------------------
Why did we take PQ in the dijkstra? 
Because we needed the smallest

PQ cannot erase an element
Set can

Why do we need that?

If say, at some step, dist[5] is 10 == means this is not infinity - means someone already reached node 5
in a distance of 10. Lets say, some other node is reaching 10 with a distance of 8 now ->
we can remove the older pair for (10, 5) and put (8, 5)

PQ did not have this option !

And <10, 5> vaise bhi kabhi retrieve nahi hota if <8,5> ek baar queue me nahi aata

This improves the time complexity very minorly

Set.erase is a O(log) operation

The time complex can be said almost the same

But Set is better because ->
1. because it stores unique
2. because it also set stores everything in ascending way
3. Most importantly, We can erase in set but not in PQ

------------------------------------------------------------------------------------------------------------------------

Why a PQ or a set ?
Because queue can also gives us an answer
It is bfs only end of the day


