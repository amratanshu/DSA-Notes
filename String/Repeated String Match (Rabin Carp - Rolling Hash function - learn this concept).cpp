RABIN CARP - 
Concept ->

Text string - ccaxyzabcd

Pattern to search in text - abc

If we assign a digit to each letter - lets keep it simple and a=1, b=2 etc..

Then the rabin carp method says

For every pattern - (in our case - 3 letter pattern) - use a hash function to find its value

Lets Take a simple hash function - basic addition

Then abc would be 1 + 2 + 3

Now in the full string text - in every window of size 3 - calculate that window ka hash - called ROLLING HASH checking

Also - when moving from window 1 to window 2 - jsut subtract char 1 value of window 1 and add char 3 value of window 3 - 
this way it is an O(1) operation when moving windows and calculating the new hash value

If the hash is same - (addition of digits) - then it COULD be a potential match

Manually confirm it by comparing each letter.


------------------------------------------------------------------------------------------------------------

SPURIOUS HITS ->

There might not be a match as well

For eg - cca and dba - both strings ka hash value is same - because  3 + 3 + 1 === 4 + 2 + 1

We will know only in manual character checking - that they are unequal strings

But this is bad - 

------------------------------------------------------------------------------------------------------------

COMPLEXITY ->
TEXT of - size N
Pattern to find in text - Size M

If no spurious hits -  O(N-M+1)

WORST CASE - If all suprious hits - O(MN)

------------------------------------------------------------------------------------------------------------

BETTER HASH FUNC - suggested by Rabin - 

kind of like doing decimal number system value

a b c

If base = 10
1*10^2 + 2*10^1 + 3*10^0

Rabin suggests to keep the base as the number of characters expected in the system

Eg - If only  small alphabets are expected - total 26 - keep 26 base

abc 
1*26^2 + 2*26^1 + 3*26^0

In ASCII - total 127 characters are there

------------------------------------------------------------------------------------------------------------

ROLLING HASH -

To optimise on the changing hash value and its re calculation everytime

We do this - 

if text is
ccacca

window 1 - cca
window 2 - cac

When moving from window 1 to 2 - we have to subtract the value given by first c in 1. and then add the value given by third c in 2.

From complete hash value of CCA - subtract 3*26^2

Then multiply this value by base i.e multiple by 26

Then add value of third c in window 2 (base 26 power 0)

This way - this is a quick operation


------------------------------------------------------------------------------------------------------------

Remember how to handle overflow

we can get very large values

So do a mod

If it is a 32 bit data type (int) - then mod by 2^31 - because 1 bit is sign bit

Depends totally on the language and the data type we select


IMPLEMENTATION OF RABIN CARP IN C++ ->

Problem - https://leetcode.com/problems/repeated-string-match/

Read the implementation again and again to understand it clearly

Do a dry run

class Solution {
public:
    // s1 is the text
    // s2 is the pattern

    // rolling hash - hash calculation in sliding window form
    int rabin_karp(string s1, string s2) {
        long long m = s1.size();
        long long n = s2.size();

        long long p = 31;
        long long pow = 1;
        long long mod = 1e9 + 7;
        long long targetHashVal = 0;

        // hash value of pattern
        for (long long i = 0; i < n; i++) {
            targetHashVal = (targetHashVal + (s2[i] - 'a' + 1) * pow) % mod;
            pow = (pow * p) % mod;
        }

        // rabin carp
        // prefix hash array
        vector<long long> pha(m);

        // power array - to save time for calculating exponential powers
        vector<long long> pa(m);

        pha[0] = s1[0] - 'a' + 1;
        pa[0] = 1;
        pow = p;

        for (long long i = 1; i < m; i++) {
            pha[i] = (pha[i - 1] + (s1[i] - 'a' + 1) * pow) % mod;
            pa[i] = pow;
            pow = (pow * p) % mod;
        }

        // Now Start sliding window
        //  initialize variables for the starting and ending points of window
        long long sp = 0, ep = n - 1;

        while (ep < m) {
            long long win = pha[ep];
            if (sp > 0)
                win = (win - pha[sp - 1] + mod) %
                      mod; // agar value negative hoti hai toh usme bas mod add
                           // kardo

            if (win == (targetHashVal * pa[sp]) % mod) {
                return 1;
            }
            sp++, ep++;
        }
        return 0;
    }

    int repeatedStringMatch(string a, string b) {
        if (a == b)
            return 1;

        int count = 1;
        string source = a;

        while (source.size() < b.size()) {
            source += a;
            count++;
        }

        if (source == b)
            return count;

        if (rabin_karp(source, b) == 1)
            return count;

        if (rabin_karp(source + a, b) == 1)
            return count + 1;

        return -1;
    }
}
;