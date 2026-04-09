https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

BFS with a twist.

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if (start == end) return 0;
        
        // dist array handles the "visited" logic and stores min steps
        // Size is 100,000 because of the modulo
        vector<int> dist(100000, 1e9); 
        dist[start] = 0;
        
        queue<pair<int, int>> q; 
        q.push({0, start});
        
        int mod = 100000;
        
        while(!q.empty()) {
            int steps = q.front().first;
            int curr = q.front().second;
            q.pop();
            
            for(auto ele : arr) {
                int newStart = (1LL * curr * ele) % mod; // Use 1LL to prevent overflow before modulo
                
                // If we find the end, the first time we find it in BFS is the shortest
                if (newStart == end) return steps + 1;
                
                // Only push to queue if we found a shorter path to this specific number
                if (steps + 1 < dist[newStart]) {
                    dist[newStart] = steps + 1;
                    q.push({steps + 1, newStart});
                }
            }
        }
        
        return -1;
    }
};