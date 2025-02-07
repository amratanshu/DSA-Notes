https://leetcode.com/problems/design-add-and-search-words-data-structure/?envType=company&envId=tiktok&favoriteSlug=tiktok-thirty-days

Not my own solution
But anyway - TRIE + DFS 

"." are allowed and represent any wildcard character - so we do a recursive check to cover all possbilities

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class WordDictionary {
private:
    Node* root;

    bool searchHelper(string &word, int index, Node* node) {
        if (index == word.length()) {
            return node->isEnd();
        }

        char ch = word[index];
        if (ch == '.') {
            // Explore all possible children
            for (int i = 0; i < 26; i++) {
                if (node->links[i] != NULL) {
                    if (searchHelper(word, index + 1, node->links[i])) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            if (!node->containsKey(ch)) {
                return false;
            }
            return searchHelper(word, index + 1, node->get(ch));
        }
    }

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};
