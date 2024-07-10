Directed graph detect cycle using BFS

CONCEPT:

This is done using Kahns algorithm - Topological graph

1. Find the indegrees for all the nodes
2. start with the queue and keep the nodes with 0 indegree

CONCEPT - if we apply topo sort algo - we should get all the N nodes in that order. But topo is only applicable for ACYCLIC. only then it works.

In this case - if we do TOPO S on a CYCLIC - then the number of nodes in the sorting will be less than n. When this happens - we can say graph is CYCLIC !!

this happens because during topo sort - the queue becomes empty pehle hi

ANSWER =

- JUST CALL TOPO SORT - 

if topo.size() < V return true; else return false; !!!
