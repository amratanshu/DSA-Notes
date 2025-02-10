https://leetcode.com/problems/text-justification/solutions/3584148/text-justification/?envType=company&envId=tiktok&favoriteSlug=tiktok-thirty-days

Just do what it says.

First task - find what words will be on each line

Then - start doing what it says.

To determine number of spaces to distribute - either u can do it evenly (divide karo and no modulus) OR
extra spaces on the left required! 

from the left - how many words will have extra spaces?
USE -> needsExtraSpaces = extraSpaces % wordCount    

But be ware of special cases ->

1. Last line is handled separately - because of left alignment
2. If a line contains only one word - It is also the final word - so final word should not have any spaces behind it

Beause of case 2 - we run into some division by zero when trying to calculate the spacesPerWord - so keep in MIND!

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        while (i < words.size()) {
            vector<string> currentLine = getWords(i, words, maxWidth);
            i += currentLine.size();
            ans.push_back(createLine(currentLine, i, words, maxWidth));
        }
        return ans;
    }

private:
    vector<string> getWords(int i, vector<string>& words, int maxWidth) {
        vector<string> currentLine;
        int currLength = 0;
        while (i < words.size() && currLength + words[i].size() <= maxWidth) {
            currentLine.push_back(words[i]);
            currLength += words[i].size() + 1;
            i++;
        }
        return currentLine;
    }
    string createLine(vector<string>& line, int i, vector<string>& words,
                      int maxWidth) {
        int baseLength = -1;
        for (const string& word : line) {
            baseLength += word.size() + 1;
        }
        int extraSpaces = maxWidth - baseLength;
        if (line.size() == 1 || i == words.size()) {
            string res = join(line, " ");
            res += string(extraSpaces, ' ');
            return res;
        }
        int wordCount = line.size() - 1;
        int spacesPerWord = extraSpaces / wordCount;
        int needsExtraSpace = extraSpaces % wordCount;
        for (int j = 0; j < needsExtraSpace; j++) {
            line[j] += " ";
        }
        for (int j = 0; j < wordCount; j++) {
            line[j] += string(spacesPerWord, ' ');
        }
        return join(line, " ");
    }
    string join(vector<string>& line, const string& delimeter) {
        if (line.empty()) {
            return "";
        }
        string res(line[0]);
        for (int i = 1; i < line.size(); i++) {
            res += delimeter + line[i];
        }
        return res;
    }
};