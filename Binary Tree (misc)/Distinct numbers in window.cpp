Easy AF - https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    if (B > n) return {};
    
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int i=0;i<n;i++) {
        if (i < B)
            mp[A[i]]++;
        else {
            ans.push_back(mp.size());
            
            mp[A[i-B]] --;
            if (mp[A[i-B]] == 0)
                mp.erase(A[i-B]);
            
            mp[A[i]]++;
            
            
        }
    }
    ans.push_back(mp.size());
    return ans;
}
