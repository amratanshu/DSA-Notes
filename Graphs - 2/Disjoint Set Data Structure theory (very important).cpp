https://www.youtube.com/watch?v=aBxjDBC4M1U&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=46&ab_channel=takeUforward

Watch this video multiple times!

We are creating a data structure called - disjoint set
with functions ->

union(u, v) -- basically connecting two nodes into a single component
findParent(u)

we can implement union using 2 methods ->

1. Rank method
2. Size method

Lets discuss the Rank method for now ->

------------------------------------------------------------------------------------------------------------

You are given all the edges in a graph

Create two arrays ->

Rank(size n, all assigned to 0)
[0 0 0 0 0 0 0 0 0 0]

Parent(size n, all assigned to themselves = i)
[1 2 3 4 5 6 7 8]

This is considering 1 based indexing as of now

------------------------------------------------------------------------------------------------------------

PSEUDOCODE for UNION(u, v)

1. Find ultimate parent of u and v - call them pu and pv

2. Find rank of pu and pv

3. Connect smaller rank to larger rank. If same rank - connect any one to the other
Adjust the parents and ranks accordingly here - for obvious reasons

------------------------------------------------------------------------------------------------------------
HOW TO CHECK IF TWO NODES BELONG TO THE SAME SET?

After we are done doing this for some edges - we will have some connected components..

If we want to see if two nodes are in the same edge - 

we just need to know whether their ultimate parents are the same

If same - they are in the same set

BUT - finding the ultimate parent - would require going up the tree everytime

So - we do something like - PATH COMPRESSION
------------------------------------------------------------------------------------------------------------

PATH COMPRESSION ->

basically - whenever we travel once from a node to its ultimate parent - on the way - for each node we mark
the parent of that node to be the ultiamte parent 

basically - if the root is x - and the path from x to some node y - contains other elements

After path compression - all elements in that path - will now be directly connected to x (the root) itself

connected how? we will do parent = x (in a recursive backtracking way)

Basically - we are erasing their internal parent relationships at all because we dont need them.

By doing this - findParent() for any node - runs in constant time almost

------------------------------------------------------------------------------------------------------------

CODE ->

#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}