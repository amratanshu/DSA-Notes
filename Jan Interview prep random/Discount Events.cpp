https://www.fastprep.io/problems/amazon-discount-events

Find the maxi element till now
O(N) solution only. No need to make it O(N^2)

#include<bits/stdc++.h>
class Solution {
public:
  vector<int> finalPrices(int n, vector<int> price, int q, vector<vector<int>> queries) {
    int maxi = INT_MIN;
    for(auto q: queries) {
      if (q[0] == 2) {
        maxi = max(maxi, q[1]);
      }
    }
    
    // vector<int> res(n, -1);
      
      
      for(auto q: queries) {
        if (q[0] == 1) {
          price[q[1]-1] = q[2];
        }
      }

      for(int i=0; i<n; i++) {
        if (price[i] < maxi) price[i] = maxi;
      }
      return price;
      
  }
  };