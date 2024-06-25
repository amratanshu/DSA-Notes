Easy - 
Just read the push method and do a dry run and you will be fine

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        if (q.size() == 0) {
            q.push(x);
            return;
        }

        int prevSize = q.size();

        q.push(x);
        while(prevSize -- > 0) {
            int popped = q.front();
            q.pop();
            q.push(popped);
        }
    }
    
    int pop() {
        if (q.size() == 0)
            return -1;
        
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        if (q.size() == 0)
            return -1;
        
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */