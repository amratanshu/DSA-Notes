https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {

        // many ways
        // one is traverse from the end and use a stack to reverse the
        // characters

        // another - have an ans and a temp string - traverse starting se - if
        // you get a space - do ans = temp + ans note - dont do ans = ans +
        // temp; this will maintain the reverse format

        stack<string> st;
        string word;
        for (char ch : s) {
            if (ch == ' ' && word.length()) {
                st.push(word);
                word = "";
            } else if (ch != ' ')
                word += ch;
        }
        string res;
        if (word.length())
            res = word; //last word
        else {
            res = st.top();
            st.pop();
        }
        while (!st.empty()) {
            res += " " + st.top();
            st.pop();
        }
        return res;
    }
};