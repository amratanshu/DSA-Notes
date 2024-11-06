https://leetcode.com/problems/encode-and-decode-strings/

Chunked encoding - 

We are storing the size of the string in a 4 character long string or characters

See the toString function to understand this

class Codec {
public:
    //chunked encoding
    string toString(int x) {
        //return a string of length 4 always, irrespective of the integer
        string temp = to_string(x);
        //pad it with empty spaces
        while (temp.size() < 4) {
            temp = '0' + temp;
        }
        return temp;
    }
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for(auto str: strs) {
            ans += toString(str.size());
            ans += str;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i < s.size()) {
            int len = stoi(s.substr(i, 4));
            i = i + 4;
            ans.push_back(s.substr(i, len));
            i = i + len;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));