https://leetcode.com/problems/reorganize-string/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days

Note - Not my solution!

Hint - Alternately place the most common characters

Use priority queue to store chars in descending order of frequencies

Approach ->

Initialization:

Count the frequency of each character in the string.
Populate the max heap with these frequencies.
Processing Each Character:

Pop the top two characters from the max heap (i.e., the ones with the highest frequency).
Append these two characters to the result string.
Decrement their frequencies and re-insert them back into the max heap.
If only one character remains in the heap, make sure it doesn't exceed half of the string length, otherwise, return an empty string.
Wrap-up:

If there's a single remaining character with a frequency of 1, append it to the result.
Join all the characters to return the final reorganized string.

#include <string>
#include <map>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool comparator(char a, char b, const map<char, int>& m) {
        return m.at(a) > m.at(b);
    }

    string reorganizeString(string s) {
        map<char, int> m;
        for (char c : s) {
            m[c]++;
        }

        std::vector<char> sorted;
        for (auto pair : m) {
            sorted.push_back(pair.first);
        }

        sort(sorted.begin(), sorted.end(), comparator(a, b, m)) {
            return comparator(a, b, m);
        });

        if (m[sorted[0]] > (s.size() + 1) / 2) {
            return "";
        }

        std::string res(s.size(), ' ');
        int i = 0;
        for (char c : sorted) {
            for (int j = 0; j < m[c]; j++) {
                if (i >= s.size()) {
                    i = 1;
                }
                res[i] = c;
                i += 2;
            }
        }

        return res;
    }
};
