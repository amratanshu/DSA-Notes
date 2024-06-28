https://leetcode.com/problems/compare-version-numbers/description/
Easy question

O( N ) + O( size of subpart of string ) ;
N is the maximum size among two version strings.


This is my solution using stoi

Try to do it without using stoi also

That can be done by having a comparsion logic of base1 and base2 strings - eg how to compare 2 and 10 as a string
without converting to integer

Custom implementation of STOI - 

long long  solve( string s )
{
    long long n = 0 ;
    int i = 0 ;
    while( i < s.size() ) 
    {
        n += n*10 + (s[i]-'0') ;
        i++ ;
    }
    return n ;
}

--------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int compareVersion(string version1, string version2) {
        // find base versions for both first
        int n = version1.length(), m = version2.length();
        int i = 0, j = 0;
        string base1;
        string base2;

        while (1) {
            base1 = "";
            base2 = "";
            // if strings are over - their missing versions are assume to be 0
            if (i >= n)
                base1 = "0";
            if (j >= m)
                base2 = "0";

            while (i < n && version1[i] != '.') {
                base1 += version1[i];
                i++;
            }
            i++;
            while (j < m && version2[j] != '.') {
                base2 += version2[j];
                j++;
            }
            j++;

            cout << "base 1 is " << base1 << endl;
            cout << "base 2 is " << base2 << endl;

            if (stoi(base1) < stoi(base2))
                return -1;
            else if (stoi(base1) > stoi(base2))
                return 1;
            else {
                if (i>=n && j>=m)
                    return 0;
                continue;
            }
        }
    }
};