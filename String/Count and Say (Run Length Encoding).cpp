https://leetcode.com/problems/count-and-say/description/

Pretty easy to code

Time complexity: O(2^n)
Lets say that every string has no duplicate numbers together , therefore 
lets asssume size for n=1 is 1 , 2 is 2, 3 is 4, 4 is 8 , 5 is 16 i.e. 2^(n-1) in worst case. 
So overall complexity is a G.P. from 2^(1-1),2^(2-1),....,2^(n-1) which sums up to
g.p. sum = a(r^n - 1)/r-1
where a = 1,r = 2.
So complexity becomes 2^n - 1.

class Solution {
public:
    string countAndSay(string temp) {
        string ans = "";
        char c = temp[0];
        int count = 1;
        //initial
        if (temp.length() == 1)
        {
            return to_string(count) + c;
        }

        for (int i=1;i<temp.length();i++) {
            if (temp[i] == c) {
                count++;
            }
            else { //mismatch - so we have to write something to the string
                ans += to_string(count) + c;
                c = temp[i];
                count = 1;
            }
        }

        ans += to_string(count) + c;
        return ans;

    }

    string countAndSay(int n) {
        if (n == 1)
            return "1";

        //lets try to solve it iteratively - follow up
        // string ans = "";
        string temp = "1";

        for (int i=0;i<n-1;i++) {

            //find the countAndSay for temp string
            temp = countAndSay(temp);
        }
        return temp;
    }
};