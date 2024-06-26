https://leetcode.com/problems/string-to-integer-atoi/

Solution is very easy - just how you read the input is important

Otherwise - it is just handling edge cases and overflow..

#include <math.h>
class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int ans = 0;

        bool ifSignRead = false;
        bool sign = true;
        string temp = "";
        for (int i = 0; i < n; i++) {
            // ignore leading spaces util no digits have been found and no sign has been read/set
            //sign checked here because - "   +  123 " ka expected answer is 0. Not 123. Sign ke just baad digits hi hone chahie
            while (i < n && s[i] == ' ' && temp=="" && ifSignRead == false)
                i++;

            if (s[i] == ' ') // we already removed blanks in the while loop - if            
            // this occurs again - stop
                break;

            else if (s[i] >= '0' && s[i] <= '9') { // if it is a number
                temp = temp + s[i];
            } else if (s[i] == '-' || s[i] == '+') {
                if (ifSignRead) // sign already read in the input
                    break;

                if (temp != "") // some integers are already read
                    break;

                ifSignRead = true;
                s[i] == '-' ? sign = false : sign = true;
            } else
                break;
        }

        if (temp != "")
            ans = convert(temp, sign);
        return ans;
    }

    int convert(string temp, bool sign) {
        int n = temp.length();
        double ans = 0;

        for (int i = 0; i < n; i++) {
            double add = pow(10, n - i - 1);
            if (!sign)
                add*=-1;
            // int digit = temp[i] - '0';

            ans += add * (temp[i] - '0');

            // overflow check as we traverse - because this string can be tooooooooo big
            if (ans < INT_MIN)
                return INT_MIN;

            if (ans > INT_MAX)
                return INT_MAX;
        }

        return (int)ans;
    }
};