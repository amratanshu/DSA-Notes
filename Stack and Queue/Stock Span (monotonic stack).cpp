https://leetcode.com/problems/online-stock-span/description/

My solution

Comments se samajh me aa jayega

It is just an implementation of finding nearest prevBigger (and its index basically).

class StockSpanner {
public:
    stack<pair<int,int>> st;
    int day = -1; 
    //since we dont have an array with indices - use this to mark which price corresponds to which day
    //in the stack
    StockSpanner() {
        
    }
    
    int next(int price) {
        day++;
        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }

        if (st.empty()) {
            st.push({price, day});
            return day+1;
        }

        int ans;
        if (st.top().first > price) {
            ans = day - st.top().second;
            st.push({price, day});
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */