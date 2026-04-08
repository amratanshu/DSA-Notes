https://leetcode.com/problems/alien-dictionary/description/

Alien Language that uses the english alphabet bruh

kind of - finding the topological sort for this new language letters.

The main thing is - how do we make up this graph in the first place?

First intuition - check every consecutive pair of words - and start forming the graph - 
by the lexicographic sorting rule !!!

If the first few chars of 2 consec strings are same - then the one after that is compared and put an edge there!

maintain an adjacency list of 26 * 26

and then in the end - if there is no topo sort possible - meaning there is a cycle - return empty

Question - is this "consecutive pair" checking enough to make the graph - or do we need to compare every word
with every word that appears ahead of it? 

Think !

Your logic is correct! Yay

Writing the code ->

1. make sure you do the dfs and cycle check only on the letters that are present - and not on all 26
letters in the eng language. maintain some present letters data structure for this

Solved completely by ME!!


class Solution {
public:
    bool dfs(int node, int vis[], int dfsvisited[], stack<int> & st, vector<vector<int>> &graph) {
        vis[node] = 1;
        dfsvisited[node] = 1;

        for(int adjNode = 0; adjNode < 26; adjNode++) {
            if (graph[node][adjNode] == 1) { // If edge exists
                if (!vis[adjNode]) {
                    if (dfs(adjNode, vis, dfsvisited, st, graph)) return true;
                } else {
                    if (dfsvisited[adjNode]) {
                        return true;
                    }
                }
            }
        }
        dfsvisited[node] = 0;
        st.push(node);
        return false;
    }

    string alienOrder(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> graph(26, vector<int>(26, 0));
        
        // Track which characters are actually in the dictionary
        bool present[26] = {false};
        for (string &word : words) {
            for (char c : word) present[c - 'a'] = true;
        }

        for (int i=1; i < n; i++) {
            string first = words[i-1];
            string second = words[i];
            if (first.size() > second.size() && first.substr(0, second.size()) == second) return "";

            int j = 0;
            while(j < first.length() && j < second.length()) {
                if (first[j] == second[j]) {
                    j++;
                }
                else {
                    graph[first[j] - 'a'][second[j] - 'a'] = 1;
                    break;
                }
            }
        }

        stack<int> st;
        int vis[26] = {0};
        int dfsvisited[26] = {0};

        for (int i=0; i<26; i++) {
            // Only run DFS if the character exists in the input words
            if (present[i] && vis[i] != 1) {
                if (dfs(i, vis, dfsvisited, st, graph)) {
                    return "";
                }
            }
        }

        string ans = "";
        while(!st.empty()) {
            // Use st.top() to get the actual value from the stack
            ans = ans + (char)(st.top() + 'a');
            st.pop();
        }

        return ans;
    }
};