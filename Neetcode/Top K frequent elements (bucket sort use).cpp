https://leetcode.com/problems/top-k-frequent-elements/description/

DO it in better time than ONLOGN - basically without sorting!

use hashmap with heap - at the peak of the heap - we will have the most sorted elements

But better approach - Bucket Sort!

https://leetcode.com/problems/top-k-frequent-elements/solutions/1927648/one-of-the-best-explanation/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //using bucket sort for most optimal approach
        int n = nums.size();
        unordered_map<int, int> m;
        for (auto e: nums) {
            m[e]++;
        }
        vector<vector<int>> bucketList(n+1); //buckets for each frequency
        for (auto itr: m) {
            int freq = itr.second;
            int key = itr.first;
            bucketList[freq].push_back(key);
        }

        vector<int> ans;
        int i = n;
        int count = 0;
        //iterate on the bucket from the end - because buckets' index are frequencies.
        while(i >= 0) {
            int bsize = bucketList[i].size();
            if (bsize != 0) {
                for(int j=0;j<bsize; j++) {
                    ans.push_back(bucketList[i][j]);
                    count++;
                    if (count == k) return ans;
                }
            }
            i--;
        }
        return ans;



    }
};