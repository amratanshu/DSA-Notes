https://www.youtube.com/watch?v=YbY8cVwWAvw&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=43&ab_channel=takeUforward

This is a multi-source shortest path algo (unlike bellman ford and dijkstra which had only one source)

This can also handle negative cycles!

This is good for finding shortest path between every node basically.

N^3 loop

Create an adjacency matrix

For all the cells in the matrix (yes, for all the cells! not just those which have nodes)
    cell is [i][j]
    do something to check if you can go from i to j via nodeX (nodeX is all nodes one by one)
    what is this "something"? just see if the distance is less than the previous one. 
    and eventually you will have the shortest cost

It is kind of like a brute force algo. And not very intuitive also.
Dont worry

