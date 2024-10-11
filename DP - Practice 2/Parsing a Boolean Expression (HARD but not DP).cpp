https://leetcode.com/problems/parsing-a-boolean-expression/

This is not a clear DP problem but - this one is -

https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
here we are not given with parenthesis and have to find the number of ways the expr evaluates to true.

The solution to this is discussed in this folder only.

This one, on the other hand - 

is very easy - directly use a stack


class Solution {
public:
    bool parseBoolExpr(string expression) {

        stack<char> st;
        int i = 0;
        int n = expression.size();
        while(i < n) {
            char c = expression[i];
            if (c == '(' || c == '|' || c == '&' || c == '!' || c == 't' || c == 'f') {
                st.push(c);
            }

            else if (c == ')') {
                string temp = "";
                while(st.top() != '(') {
                    temp = temp + st.top();
                    st.pop();
                }
                //pop the '('
                st.pop();
                char op = st.top();
                st.pop();

                if (op == '|') {
                    bool ans = false;
                    for (char tt: temp) {
                        if (tt == 't') {
                            ans = true;
                            break;
                        }
                    }
                    if (ans)
                        st.push('t');
                    else st .push('f');
                }

                else if (op == '&') {
                    bool ans = true;
                    for (char tt: temp) {
                        if (tt == 'f') {
                            ans = false;
                            break;
                        }
                    }
                    if (ans)
                        st.push('t');
                    else st .push('f');
                }

                else if (op == '!') {
                    if (temp[0] == 't') st.push('f');
                    else st.push('t');
                }
            }
            i++;
        }
        if (st.top() == 't') return true;
        else return false;
    }
};