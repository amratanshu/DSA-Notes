https://leetcode.com/problems/largest-divisible-subset/submissions/

CONCEPT -> 
use the traverse array with i and prev concept from LIS only.

If you see carefully - we have to find out subsets. not subsequences. So it need not be in
the order it appears in the array.

Hence we can use the concept of sorting the array !
If we sort it and start traversing - we can check only for whether a[i] % a[prev] == 0

kyuki uske pehle wale automatically honge hi. Toh line se saare hote chale jayenge from the 
lowest element to the largest. They'll 'be part of the same mathematical table. 
However if we dont sort - and the order of their occurence is 9 3 6 1 -> then u cant check 
just a[i] % a[prev] == 0 and fulfill the condition.

Slight change in Recursion from the prev problem: 

f(index, prev) {
    if (a[i]%a[prev] == 0 || prev == -1) {
        pick = 1 + f(i+1, i)
    }
    notPick = 0 + f(i+1, prev)
    return max(pic, notPick)
    
}

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int maxi = 1;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<int> hash(n);
        vector<int> dp(n, 1);

        int lastIndex = 0;
        for (int i=0; i<n;i++) {
            hash[i] = i;
            for (int prev=0; prev<i;prev++) {
                if (arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i]) {

                    dp[i] = dp[prev] + 1;
                    hash[i] = prev; //whenever dp is getting updated and added by 1, add the previous to backtrack.
                }
            }

            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }

        }

        vector<int> LIS;
        LIS.push_back(arr[lastIndex]); 
        while(hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            LIS.push_back(arr[lastIndex]);
        }
        reverse(LIS.begin(), LIS.end());
        return LIS;
    }
};