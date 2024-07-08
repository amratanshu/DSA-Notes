https://leetcode.com/problems/kth-largest-element-in-a-stream/

Approach - using multiset (implemented as AVL BSTs behind the scenes)

In multiset (AVL BST) ->
This approach has - 
TIME O(LogK)ForConstruction,O(LogK)ForAddition
SPACE O(N)

You can do this question as plain BSTs also - but it will be a combination of two questions
1. Insert element in a BST
2. Find kth largest element in a BST (traversal)

In plain BST ->
Time - 
Kth constructor() ->
Time : O(nLog n) : Construct Tree Of n Nodes using Insert O(Log n)
Space - O(N) - to store the N nodes

Add() function ->
Time : O(2Log n) : O(Log n) For Insert + O(Log n) For Search

class KthLargest {
public:
    int K;
    multiset<int> m; //we can do multiset<int, less<int>> but by default - the comparison functor is set to less
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (auto i : nums) {
            m.insert(i);
            if (m.size() > k) {
                m.erase(m.begin()); //always store just the last k elements so that at the first level - we have our ans
            }
        }
    }
    
    int add(int val) {
        m.insert(val);
        if (m.size() > K) {
            m.erase(m.begin());
        }
        auto itr = m.begin();
        return *itr;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */