CONCEPT:

Rule of thumb - we'll always use a Queue with BFS and Recursion with DFS

The undirected approach wont work here !
Why? because lets say 1 -> 5 <- 2 and 1 -> 2 as welll DRAW ON PAPER
Here, the dfs of 1 will give 5 and if we go through 2, then also we'll get 5 - but doesnt mean we have a cycle here.

We have to use a Self DFS with visited DFS approach

We have to create 2 visited arrays

1. visited array
2. DFSVisited array

When we come back from a dfs call - we have to mark dfsVisited = 0 again
watch striver video it will be clear

dfsVisited = 1 hai agar already - that means we have already visited it in the current DFS call or not !
