https://www.youtube.com/watch?v=YbY8cVwWAvw&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=43&ab_channel=takeUforward

This is a multi-source shortest path algo (unlike bellman ford and dijkstra which had only one source)

This can also handle negative cycles!

This is good for finding shortest path between every node basically.

N^3 loop

Create an adjacency matrix

initialize the leading diagonal as all 0s

For all the cells in the matrix (yes, for all the cells! not just those which have nodes)
    cell is [i][j]
    do something to check if you can go from i to j via nodeX (nodeX is all nodes one by one)
    what is this "something"? just see if the distance is less than the previous one. 
    and eventually you will have the shortest cost

It is kind of like a brute force algo. And not very intuitive also.
Dont worry

We have to go "Via" for all nodes

so ->

for (via = 1 to n) {
    for (i = 1 to n) {
        for (j = 1 to n)
            if (i to j VIA via) < cell[i][j]
                update values
    }
}

What is i to j VIA via ??

basically -
i to j VIA via = cell[i][via] + cell[via][j]

------------------------------------------------------------------------------------------------------------------------------------------------------------------

How to detect a cycle?

Intuition - 

The cost of going from one node to the same node == should be 0 !!

basically via[0][0] = 0 hona chahie - because we are already at the same node

but in the end - if there is a negative cycle - floyd warshall will find another path which is of negative cost


So basically if any cell[i][i] = negative == this means this graph has a negative cycle

------------------------------------------------------------------------------------------------------------------------------------------------------------------

C++ Code->

is in the screenshot.


Time complex ->

O(N^3)

SPACE ->

O(N^2) - we are using the space, even if it is given as an input - still we are usign n^2 space

------------------------------------------------------------------------------------------------------------------------------------------------------------------

WHat if we use DIJKSTRA to find shortest path for all the nodes?


We can use it only if there are not negative cycles

If no negative cycles - then doing dijkstra on every node - is actually better than N^2 time

1 dijkstra = E log V

for all V nodes -> V E Log V ---> better than N^3