https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

Pretty easy stack question

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        int n = tokens.size();
        int n1, n2;
        for (int i = 0; i < n; i++) {
            char c;
            string t = tokens[i];
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                c = tokens[i][0];

                if (c == '+') {
                    n2 = s.top();
                    s.pop();
                    n1 = s.top();
                    s.pop();
                    s.push(n1 + n2);
                } else if (c == '-') {
                    n2 = s.top();
                    s.pop();
                    n1 = s.top();
                    s.pop();
                    s.push(n1 - n2);
                } else if (c == '*') {
                    n2 = s.top();
                    s.pop();
                    n1 = s.top();
                    s.pop();
                    s.push(n1 * n2);
                } else if (c == '/') {
                    n2 = s.top();
                    s.pop();
                    n1 = s.top();
                    s.pop();
                    s.push(n1 / n2);
                }
            }
            else { //its a number, can be negative or double digit or both
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};