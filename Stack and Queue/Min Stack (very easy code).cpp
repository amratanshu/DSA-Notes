https://leetcode.com/problems/min-stack/

Store min in each element of the node.

class MinStack {
public:
    //add the elements to the stack normally but store the minimum value so far in each stack element

    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
            return;
        }
        int min = st.top().second;
        if (min < val) {
            st.push({val, min});
        }
        else st.push({val, val});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */