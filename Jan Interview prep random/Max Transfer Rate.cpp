https://www.fastprep.io/problems/amazon-max-transfer-rate

My solution ->

use ind to mark which index we are taking into the pair
Use duplicate - true to consider pair arr[ind], arr[ind]
if duplicate - false -> x,x has already been done. So now we considering x,x+1 and then x+1,x

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxTransferRate(vector<int> throughput, int pipelineCount) {
        sort(throughput.begin(), throughput.end(), greater<>());
        int ind = 0;
        int count = 0;
        bool duplicate = true;
        long long ans = 0;

        while (count < pipelineCount) { // Fixed the condition from <= to < for correct iteration
            if (duplicate) {
                ans += (long long) throughput[ind] * 2;
                duplicate = false;
                count += 1;
                if (count == pipelineCount) break;
            } else {
                if (ind + 1 < throughput.size()) {
                    long long sum = (long long) throughput[ind] + throughput[ind + 1];
                    ans += sum;
                    count += 1;
                    if (count == pipelineCount) break;

                    ans += sum;
                    count += 1;
                    
                    ind++;
                    
                    duplicate = true;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded values
    vector<int> throughput = {4, 2, 5};
    int pipelineCount = 4;

    long long result = sol.maxTransferRate(throughput, pipelineCount);
    cout << "Maximum transfer rate: " << result << endl;

    return 0;
}
