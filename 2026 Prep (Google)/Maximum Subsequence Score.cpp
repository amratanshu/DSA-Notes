https://leetcode.com/problems/maximum-subsequence-score/

First Thought ->

Sort the array but store their indices!

The trick - we need to try each element from nums2 and consider it as the minimum! - And then calculate our requirement

So for this - we need to SORT both the arrays based on the nums2 array (DECREASING order)

Like - after sorting - we need to know index wise - which ele of sorted nums2 maps to nums1.


SOLUTION ->

First we sort the nums2 array in decreasing order and as we need to know the mapping of nums2[i] to nums1[i] so for that we make their pairs and then we sort.

Now we we will iterate through p array one by one and let p[i].first as the minimum for an instance then
all the elements to left of p array can be considered for sum part.

But we can make priority queue for knowing top k elements to left of p array

And we will only keep k maximum elements at a time in priority queue and keep the tab of their sum .


We are pushing negative numbers to the PQ because this is a standard Max heap PQ

SOL1 ->


class Solution {
    public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
       vector<pair<int, int>> p ;
        
        for(int i = 0 ; i<nums1.size() ; i++)
        {
            p.push_back({nums2[i] , nums1[i]});
        }
        
        sort(p.rbegin() , p.rend());
        
        long long ans  = 0;
        long long sum  = 0;
        priority_queue<int> pq;
        for(int i = 0 ; i<k-1 ; i++)
        {
            sum += p[i].second;
            pq.push(-p[i].second);
        }

        for(int i = k-1 ; i<nums1.size() ; i++)
        {

            sum += p[i].second;
            pq.push(-p[i].second);
            
            ans = max(ans, sum * p[i].first );

            sum += pq.top();
            pq.pop();
        }
        
        return ans;
        
        
    }
};


SOL2 ->

We can use a min heap as well - by using the <greater> notation in C++ ->

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> p;
        
        for(int i = 0; i < n; i++) {
            p.push_back({nums2[i], nums1[i]});
        }
        
        // Sort descending by nums2 values
        sort(p.rbegin(), p.rend());
        
        long long ans = 0;
        long long sum = 0;
        
        // Standard Min-Heap declaration: keeps smallest element at the top
        priority_queue<int, vector<int>, greater<int>> pq;

        // Process the first k-1 elements
        for(int i = 0; i < k - 1; i++) {
            sum += p[i].second;
            pq.push(p[i].second);
        }

        // Process the rest starting from the kth element
        for(int i = k - 1; i < n; i++) {
            // Add current element to the set
            sum += p[i].second;
            pq.push(p[i].second);
            
            // Calculate score using current sum and current nums2[i] (which is the min)
            // Use 1LL to ensure multiplication doesn't overflow
            ans = max(ans, sum * (long long)p[i].first);

            // Pop the smallest element to keep the size at k-1 for the next iteration
            sum -= pq.top();
            pq.pop();
        }
        
        return ans;
    }
};