https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii/

Binary lifting concept is used here 

HARD asf question.

Havent been able to solve yet.
Unable.


DRAFT ROUGH CODE ->

class DisjointSet {
    vector<int> size;
    vector<int> parent;

public:
    // Constructor - to resize and initialize the vectors
    DisjointSet(int n) {
        size.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Recursive method which does path compression
    int findParent(int node) {
        if (parent[node] == node)
            return node;
        // return parent[node] = findParent(parent[node]);
        return findParent(parent[node]);
    }

    int findCurrentParent(int node) { return parent[node]; }
    
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

            if (ds.findParent(u) != ds.findParent(v)) { // Not in the same set yet
                cout<<"union of " <<u<<" and "<<v<<endl;
                ds.unionBySize(u, v);
                // int parent = ds.findParent(u);
                // if (parentToMaxEdgeSize.find(parent) == parentToMaxEdgeSize.end()) { // Doesn't exist in map yet
                //     parentToMaxEdgeSize[parent] = wt;
                // } else {
                //     parentToMaxEdgeSize[parent] = max(parentToMaxEdgeSize[parent], wt);
                // }
            }
        }
    }

    int findLCA(int p, int q) {
        // Find LCA first
        int temp1 = p, temp2 = q;

        unordered_set<int> parentsOf1;

        // Go to the root - for the first node
        // Include the node itself and all its ancestors
        while (ds.findCurrentParent(temp1) != temp1) {
            parentsOf1.insert(temp1);
            temp1 = ds.findCurrentParent(temp1);
        }
        // Don't forget to include the root
        parentsOf1.insert(temp1);

        // The first common ancestor when traveling upwards from temp2
        while (ds.findCurrentParent(temp2) != temp2) {
            if (parentsOf1.find(temp2) != parentsOf1.end()) { // Found
                return temp2;
            }
            temp2 = ds.findCurrentParent(temp2);
        }

        // Check the root node
        if (parentsOf1.find(temp2) != parentsOf1.end()) {
            return temp2;
        }

        return -1;
    }

    int findMaxEdge(int p, int q) { return -1; }

    bool query(int p, int q, int limit) {
        cout << ds.findCurrentParent(0)<< endl;
        cout << ds.findCurrentParent(2)<< endl;
        cout << ds.findCurrentParent(3)<< endl << endl;
        // find out the max size of edges till the LCA (least common ancestor)
        // of these nodes
        if (ds.findParent(p) != ds.findParent(q))
            return false;
        return false;
    }
};

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as
 * such: DistanceLimitedPathsExist* obj = new DistanceLimitedPathsExist(n,
 * edgeList); bool param_1 = obj->query(p, q, limit);
 */
