https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths

CONCEPT - DSU (disjoint set union) and Sorting

Read the solution! - you will understand it !

Explanation -
1. We sort the queries (store its index in the same array first because index will be lost on sorting)
2. We sort the edges
3. Now - we traverse the queries array

for each query - we see the weight
Now we add edges (add the disjoint set) from the edgeList whose weight is less than this query weight

So that way - all edges added till now - have weight less than LIMIT

No we check - if nodes p and q from this query are in the same disjoint set - perfect. TRUE



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

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
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
};

class Solution {
public:
    static bool comparator(vector<int> &e1, vector<int> &e2) {
        return e1[2] < e2[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int nq = queries.size();

        for(int i=0; i<nq; i++) {
            queries[i].push_back(i); //saving the index
        }

        sort(queries.begin(), queries.end(), comparator);
        sort(edgeList.begin(), edgeList.end(), comparator);
        vector<bool> ans(nq, false);

        DisjointSet ds(n);
        int j=0;
        for(int i=0;i<nq;i++) {
            int queryWt = queries[i][2];

            //checking all edges in the edgeList
            while(j < edgeList.size() && edgeList[j][2] < queryWt) {
                int u = edgeList[j][0];
                int v = edgeList[j][1];
                ds.unionByRank(u, v);
                j++;
            }
            int qu = queries[i][0];
            int qv = queries[i][1];
            if (ds.findParent(qu) == ds.findParent(qv)) {
                int qindex = queries[i][3];
                ans[qindex] = true;
            }
        }
        return ans;
    }
};