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

queue takes a lot more time complexity because
we have wasteful occurences of 8, 5 even when 3,5 is present in the queue

we just need the min wala everytime - GREEDY !


------------------------------------------------------------------------------------------------------------------------

How to calculate time complexity of this algo - PQ solution ->

pseudo code ->

while(!pq.empty) {
    dist, node = top

    for (iterate over adj nodes)
        if (condition)
            push

}

The outer loop - will go through all the nodes - which is V - it will kinda go 2 or 3 times - but O(V) only

Finding the top takes LOG(heap size) time
inner for loop - O(number of edges of every node) - O(NE)

In the densest graph - 
where everyone is connected to all other

so every node - has n-1 edges (or V-1 basically)

The push to PQ inside this - O(Log(heap size))

---> 

So - overall time complexity->

V * (log (heap size) + NE * log(heap size))

V* (log (Heapsize) (1 + NE))

---- NE is V-1

so ->

V * (log(heapsize) (V))

V^2 log (heapsize)

------what is heap size? in the worst case - 
if 4 nodes - all connected to each other
worst case, for each node - it will pop and check all neighbours - and push all the 3

So in this way - V^2 .... is the heapsize generally


SO final -->

V^2 log (V^2)
V^2 * 2log(V)

BUT -> if the graph is very dense (again worst case) 
what will be the number of edges?

Every node has v-1 edges

so total no of edges will also be V^2 complexity -- V * V-1


Hence ->

FINAL TIME COMPLEX ->>
2 * E * log(V)


------------------------------------------------------------------------------------------------------------------------

How to print the shortest path?

Keep a parent array - basically tracking the node where we came from !!

Everytime you find a minimum distance for a node - update its parent node also

And then in the end - we can backtrack

path ans will be 

finalNode ka parent ka parent ka parent ka parent..

Initialize the parent array - with the nodes themselves


Question on Dijkstra - https://leetcode.com/discuss/interview-question/731911/please-share-dijkstras-algorithm-questions

