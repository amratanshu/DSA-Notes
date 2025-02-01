https://leetcode.com/problems/count-vowel-strings-in-ranges/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days

count vowel strings in ranges

Range Query - Range update problem
 
Diff array nikalo

Then add the CHANGE to the lower bound. Subtract the CHANGE from the (higher+1) ele

Then do prefix sum of this diff array.

Thats it.

But here - just prefix sum is enough

Prefuix sum of occurences (give 1 if string satisfies condition and 0 if not)

Then ans for each query - prefix[high] - prefix[low - 1]


class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix;
        unordered_map<char, int> vowels;
        vowels['a'] = 1;
        vowels['e'] = 1;
        vowels['i'] = 1;
        vowels['o'] = 1;
        vowels['u'] = 1;

        for(auto w: words) {
            if ((vowels.find(w[0]) != vowels.end()) && (vowels.find(w[w.size()-1]) != vowels.end())) {
                prefix.push_back(1);
            }
            else prefix.push_back(0);
        }

        
        //calculate prefix sum now
        for(int i=1; i<n; i++) {
            prefix[i] += prefix[i-1];
        }

        vector<int> ans;
        for(auto q: queries) {
            int low = q[0];
            int high = q[1];

            if (low-1 < 0) ans.push_back(prefix[high]);
            else ans.push_back(prefix[high] - prefix[low-1]);

        }
        return ans;
    }
};