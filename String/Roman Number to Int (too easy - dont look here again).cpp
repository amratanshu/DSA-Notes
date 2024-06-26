class Solution {
public:
    int romanToInt(string s) {
        
        int ans = 0;

        for (int i=0;i<s.length();i++) {
            
            if (s[i] == 'I') {
                if (i+1<s.length() && s[i+1] == 'V') {
                    ans += 4;
                    i++;
                    continue;
                }

                if (i+1<s.length() && s[i+1] == 'X') {
                    ans += 9;
                    i++;
                    continue;
                }

                ans += 1;
            }

            if (s[i] == 'X') {
                if (i+1<s.length() && s[i+1] == 'L') {
                    ans += 40;
                    i++;
                    continue;
                }

                if (i+1<s.length() && s[i+1] == 'C') {
                    ans += 90;
                    i++;
                    continue;
                }

                ans += 10;
            }

            if (s[i] == 'C') {
                if (i+1<s.length() && s[i+1] == 'D') {
                    ans += 400;
                    i++;
                    continue;
                }

                if (i+1<s.length() && s[i+1] == 'M') {
                    ans += 900;
                    i++;
                    continue;
                }

                ans += 100;
            }

            if (s[i] == 'V')
                ans += 5;

            if (s[i] == 'L')
                ans += 50;

            if (s[i] == 'D')
                ans += 500;

            if (s[i] == 'M')
                ans += 1000;
        }
        return ans;
    }
};