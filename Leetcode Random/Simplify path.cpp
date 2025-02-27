https://leetcode.com/problems/simplify-path/description/?envType=company&envId=facebook&favoriteSlug=facebook-thirty-days

My stack solution!

Note - Why are we not reversing the directories in the stack?

While rebuilding the ans from the stack ->
Since we are prepending (ans = "/" + st.top() + ans;), this naturally builds the correct order without needing reversal.

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp = "";
        int n = path.size();

        for (int i = 0; i <= n; i++) { // Include n to handle last component
            if (i < n && path[i] != '/') {
                temp += path[i]; 
            } else {
                if (!temp.empty()) {
                    if (temp == "..") {
                        if (!st.empty()) st.pop();
                    } else if (temp != ".") { 
                        st.push(temp);
                    }
                }
                temp = "";
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans = "/" + st.top() + ans; // Build path from stack
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};
