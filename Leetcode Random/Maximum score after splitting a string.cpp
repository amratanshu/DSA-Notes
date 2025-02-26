https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2025-01-01

My solution ->
Note - handle edge cases nicely

I have created two arrays - one to track the cumulative number of 0s from the left and another array to track
the cumulative number of 1s from the right

O(N) space and time complexity

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        if (n == 2) {
            if (s[0] == '0' && s[1] == '1') return 2;
            if (s[0] == '0' && s[1] == '0') return 1;
            if (s[0] == '1' && s[1] == '1') return 1;
            if (s[0] == '1' && s[1] == '0') return 0;
        }
        vector<int> left0;
        vector<int> right1(n, 0);

        int count = 0;
        for(int i=0; i<n; i++) {
            if (s[i] == '0') count++;
            left0.push_back(count);
        }

        count = 0;
        for(int i=n-1; i>=0; i--) {
            if (s[i] == '1') count++;
            right1[i] = count;
        }

        int ans = INT_MIN;
        for(int i=1; i<n-1; i++) {
            ans = max(ans, left0[i] + right1[i]);
        }
        return ans;
    }
};

Better solution ->

class Solution {
public:
    int maxScore(string s) {
        int Total_Zeros=0;
        for(char c:s){
            if(c=='0')Total_Zeros++;
        }
        int ans=-1;
        int zeros=0;
        int L=s.length();
        for(int i=1;i<L;i++){
            if(s.at(i-1)=='0'){
                zeros++;
                Total_Zeros--;
            }
            ans=max(ans,(zeros+(L-Total_Zeros-(i))));
        }
        return ans;
        
    }
};