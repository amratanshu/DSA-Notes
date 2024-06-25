https://leetcode.com/problems/longest-string-chain/submissions/

SAME LIS Concept with condition different than just "increasing"

Sorting of array required first so that a[prev] can be a predecessor of a[i] !

After sorting - just plug the method isPredecessor in LIS code
isPred() in place of > and you are good to go!

class Solution {
public:
    static bool compareStringLen(string& s1, string& s2) {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& arr) {

        int n = arr.size();

        sort(arr.begin(), arr.end(), compareStringLen);
        
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl<<endl;
        
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i=0; i<n;i++) {
            for (int prev=0; prev<i;prev++) {
                if (isPredecessor(arr[prev], arr[i])) {
                    if (dp[prev] + 1 >dp[i])
                        cout<<arr[prev]<<" ";
                        
                    dp[i] = max(dp[i], dp[prev] + 1);
                    
                    
                }
            }

            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }

    bool isPredecessor(string a, string b) //returns if word1 is a pred of word2
    {
        if (a.length() + 1 != b.length())
            return false;
        int ptr1 = 0,ptr2 = 0;
        int n1 = a.size(),n2 = b.size();
        while(ptr1<n1 && ptr2<n2)
        {
            if(a[ptr1]==b[ptr2])
            {
                ptr1++;
                ptr2++;
            }
            else
            ptr2++;
        }
        if(ptr1==n1)
        return true;
        return false;
    }
};