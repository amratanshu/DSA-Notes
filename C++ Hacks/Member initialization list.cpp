Here, we have initialized the constructor for Disjoint set along with the constructor for 
DistanceLimitedPathsExist

Another small example is given after this code -


class DisjointSet {
    vector<int> size;
    vector<int> parent;
    
public: 
    DisjointSet(int n) {
        size.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u != ulp_v) {
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    }
};

class DistanceLimitedPathsExist {
    DisjointSet ds;
    map<int, int> parentToMaxEdgeSize;

public:
    static bool comparator(vector<int>& e1, vector<int>& e2) {
        return e1[2] < e2[2];
    }

    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList) : ds(n) {
        sort(edgeList.begin(), edgeList.end(), comparator);
        for (auto& edge : edgeList) {
            int wt = edge[2];
            int u = edge[0];
            int v = edge[1];

            if (ds.findParent(u) != ds.findParent(v)) {
                ds.unionBySize(u, v);
                int parent = ds.findParent(u);
                if (parentToMaxEdgeSize.find(parent) == parentToMaxEdgeSize.end()) {
                    parentToMaxEdgeSize[parent] = wt;
                } else {
                    parentToMaxEdgeSize[parent] = max(parentToMaxEdgeSize[parent], wt);
                }
            }
        }
    }
    
    bool query(int p, int q, int limit) {
        if (ds.findParent(p) != ds.findParent(q)) return false;
        return parentToMaxEdgeSize[ds.findParent(p)] < limit;
    }
};

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * DistanceLimitedPathsExist* obj = new DistanceLimitedPathsExist(n, edgeList);
 * bool param_1 = obj->query(p, q, limit);
 */




Another ex -

#include <string>
using namespace std;

class Address {
    string city;
    string state;
    string country;

public:
    // Constructor for Address
    Address(string city, string state, string country) 
        : city(city), state(state), country(country) {}

    // Function to get address details as a string
    string getAddress() const {
        return city + ", " + state + ", " + country;
    }
};
