Easy implementation of https://leetcode.com/problems/min-cost-to-connect-all-points/description/

class DisjointSet {
    vector<int> size;
    vector<int> parent;
    public: 
        //constructor - to resize and initialize the vectors
        DisjointSet(int n) {
            size.resize(n);
            parent.resize(n);
            for(int i=0;i<n;i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        //recursive method which does path compression
        int findParent(int node) {
            if (parent[node] == node) return node;
            else {
                return parent[node] = findParent(parent[node]);
            }
        }

        void unionBySize(int u, int v) {
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);

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

int findMst(vector<tuple<int, int, int>> edges, int n) {
    sort(edges.begin(), edges.end());
    int sum = 0;

    DisjointSet ds(n);
    for (auto edge: edges) {
        int wt = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);
        if (ds.findParent(u) != ds.findParent(v)) { //not in the same disjoint set - so we can consider this edge
            ds.unionBySize(u, v);
            sum += wt;
        }
    }

    return sum;
    
}
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<tuple<int, int, int>> edges;
        for (int i=0;i<points.size();i++) {
            for (int j=i+1; j<points.size(); j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                edges.push_back(make_tuple(abs(x1-x2) + abs(y1-y2), i, j));
            }
        }
        return findMst(edges, points.size());
    }
};