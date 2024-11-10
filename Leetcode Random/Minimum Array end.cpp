https://leetcode.com/problems/minimum-array-end/description/?envType=daily-question&envId=2024-11-09

BITMASKING

good bit manipulation question

Naive solution ->

Do bitwise OR of 0, 1, 2, .... with x - and count whenever a new number is popping up.

This is accepted for 650/750 test cases. 
Gives TLE for others.

also - this solution takes a lot of space because we are storing each new number in a set.

TLE SOLUTION ->
class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans;
        long long i = 0;
        set <long long> s;
        //start doing bitwise OR operation of x with 0, 1, 2 ...
        while(true) {
            ans = i | x;
            if (!s.contains(ans)) {
                s.insert(ans);
                if (s.size() == n) return ans;
            }
            i++;
        }
        return ans; //will never reach here
    }
};


BETTER SOLUTION ->

Do it on paper to understand more ->

Basically - say x = 10

binary -  0 0 1 0 1 0

To create new numbers from this - we have to start varying the 0s such that they are incrementing as COUNTING whole numbers

And dont touch the 1s ever!

and our answer will be - the 0s in the binary implementation of 10 - if they represent n-1 = that is our answer!

"MERGE" x and n-1 like this!
To merge x with another number v, 
keep the set bits of x untouched, for all the other bits, 
fill the set bits of v from right to left in order one by one.

SOLUTION ->

class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long number = (long long) n-1;
        long count = 1;
        
        while(number) {
            if ( !(x & count) ) { //if nth bit is NOT SET in x -> then -
                //number & 1 gives this ith bit of number - which we have to COPY onto ans.
                long long bit = (number & 1) * count;
                ans = ans | bit;
                number >>= 1;
            }
            count <<= 1;
        }
        return ans;
    }
};


Can also be done using BITSET in C++ -> to avoid using shift operators and stuff

#include <bitset>
class Solution {
public:
    long long minEnd(int n, int x) {
        std::bitset<64> X(x), N(n - 1), result(0);

        int j = 0;
        for (int i = 0; i < 64; i++) {
            if (X[i]) {
                result[i] = 1;
            } else {
                result[i] = N[j];
                j++;
            }
        }

        return result.to_ullong();
    }
};