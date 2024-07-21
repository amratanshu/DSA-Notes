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

Bellman ford - can solve negative edges also

But Bellman ford also cannot solve Negative Cycles!
How to detect negative cycles??

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

------------------------------------------------------------------------------------------------------------
Why N-1 iterations only?

Edges can be in any particular order

In each iteration - we will update each edge one by one
All dists will be inf initially
Except the first starting node - which we set to 0

This edge 0 will fulfill the relax condition and change the value of edge 1
Similarly next iteration me - edge 1 will update the edge 2

At the end of all iterations - 
We will have updated all the edges with the minimum distance

------------------------------------------------------------------------------------------------------------

How to detect Negative Cycles? 

if there is such a cycle - every iteration on this cycle - will give us a path with lower travel distance

So if we keep on iterating - the values will keep reducing

But in normal graphs - the minimum distance will be populated in the dist array at the end of N-1 iterations

But here - even the Nth iteration - will populate it with even lower values

If this happens - that means - this graph has a negative cycle brother

So --- if on Nth iteration - dist array gets updated - NEGATIVE CYCLE EXISTS

------------------------------------------------------------------------------------------------------------

CODE ->
easy very

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    // Nth relaxation to check negative cycle
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return { -1};
        }
    }


    return dist;
}


------------------------------------------------------------------------------------------------------------

TIME COMPLEX --

Very easy ->
V * E - because of the loop

SPACE - 
V


This is bit more time than Dijkstra !