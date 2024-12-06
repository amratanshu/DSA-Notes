https://leetcode.com/problems/string-compression/

My solution ->

Basic pointer question - but writing the loop was confusing.

class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) return 1;
        
        int newPointer = 0;
        int i = 0;
        while (i < chars.size()) {
            char currentChar = chars[i];
            int count = 0;
            while (i < chars.size() && chars[i] == currentChar) {
                count++;
                i++;
            }
        
            chars[newPointer++] = currentChar;
        
            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[newPointer++] = c;
                }
            }
        }
        
        chars.resize(newPointer); // Resize the vector to the new length
        return newPointer;
    }
};
