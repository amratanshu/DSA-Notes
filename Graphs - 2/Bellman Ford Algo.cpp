https://www.youtube.com/watch?v=0vVofAhAYjc&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=42&ab_channel=takeUforward

This also finds the shortest path

Bellman is applicable only in DG - directed graph

In undirected - how?
Consider one edge as 2 directed edges!

So just change this to accomodate undirected graphs!!

------------------------------------------------------------------------------------------------------------

Dijkstra fails with TLE - infinite loop when
1. negative edges
2. negative cycle

Bellman ford - helps us with this.

------------------------------------------------------------------------------------------------------------

Edges can be given in any order

1. do a relaxation of the edges N-1 times

relax the edges - means - just update the dist[] like we did in Dijkstra

if (dist[u] + w < dist[v])
    dist[v] = dist[u] + w

Do this N-1 iterations

So baar baar saari edges pe ye loop run karo basically

Also - check everytime if dist[u] == INT_MAX

because if yes - we cant do this relaxation at all - as we havent reached this node yet

and in code also - we cant do dist[u] + w - because it will overflow!