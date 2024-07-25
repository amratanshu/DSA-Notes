https://leetcode.com/problems/cheapest-flights-within-k-stops/

Bellman ford with a twist

Imagine bellman fords logic - 
in the first iteration - we have reached the nodes NEXT to 0
in the second iteration - we have reached the nodes 2 steps from 0 

So k iterations means k stops!

but we need a temp array here inside the loop

say there is an edge from 0 to 1 and 1 to 2
mark distp[0] = 0
in the first iteration only 
    in the first relaxation - we mark dist[1] .. (it is not INT_MAX anymore)
    in the second relaxation - we mark dist[2] .. but we dont want to do this right now - we want to mark
        nodes which are two steps away in the next iteration. So we create a temp array and try to do this

Iterations: Run the Bellman-Ford algorithm for k+1 iterations to consider paths with up to k stops.

Temporary Array: Use a temporary array temp to store the costs for the current iteration. 
This prevents the current iteration ka updates from affecting the next edge relaxations 
within the same iteration.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> costs(n, INT_MAX);
        costs[src] = 0;

        //n-1 iterations for bellman ford but we want to run till only k stops!
        for(int i=0;i<=k;i++) {
            vector<int> temp = costs;
            //for each edge
            for (int j=0; j<flights.size(); j++) {
                int u = flights[j][0];
                int v = flights[j][1];
                int costEdge = flights[j][2];

                if (costs[u] != INT_MAX && costs[u] + costEdge < temp[v]) {
                    temp[v] = costs[u] + costEdge;
                }
            }
            costs = temp;

        }
        if (costs[dst] == INT_MAX) return -1;
        else return costs[dst];
    }
};