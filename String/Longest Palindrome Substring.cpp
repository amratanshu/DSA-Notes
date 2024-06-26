2 Pointer approach

O(N^2)

OUTWARD EXPANSION - two pointers expanding from centre - at each A[i]..

class Solution {
public:
    string longestPalindrome(string s) {

        //two pointer approach
        
        //traversing the string - think of each character as the middle of a palindrome string and
        //we need to expand from that character as the center. expand outwards and keep checking
        //note - that this solution is for odd length strings. For even length strings, we just need to do something
        //slightly different

        //in odd - left and right were both equal to i first
        //for even len strings - we can keep left as the current ele and right starts from right (same as in odd)

        int len = 0;
        string ans = "";

        for (int i=0;i<s.length();i++) {
            int left = i, right = i;
            
            //this is for odd strings
            //check out of bounds and if it is a palindrome
            while(left>=0 && right<s.length() && s[left] == s[right]) {
                if (right - left + 1 > len) {
                    len = right - left + 1;
                    ans = s.substr(left, right-left+1);
                }

                left --;
                right++;
            }

            left = i;
            right = i+1;
            //this is for even strings
            //check out of bounds and if it is a palindrome
            while(left>=0 && right<s.length() && s[left] == s[right]) {
                if (right - left + 1 > len) {
                    len = right - left + 1;
                    ans = s.substr(left, right-left+1);
                }

                left --;
                right++;
            }
        }

        return ans;

    }
};