This is the same as Next greater element - just opposite

My solution - 

https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &A) {
    
    stack<int> st;
    vector<int> G;
    if (A.size() == 1) {
        G.push_back(-1);
        return G;
    }
    
    if (A.size() == 0) {
        return G;
    }
    
    st.push(A[0]);
    G.push_back(-1);
    for (int i=1; i<A.size(); i++) {   
        while(!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        
        if (st.empty()) {
            G.push_back(-1);
            st.push(A[i]);
            continue;
        }
        
        if (st.top() < A[i]) {
            G.push_back(st.top());
            st.push(A[i]);
        }
    }
    
    return G;
}
