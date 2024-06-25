https://leetcode.com/problems/powx-n/

Good question 

Simple concept - Binary exponentiation

if n = 17 (not divisible by 2)
then x * func(x,16)

else 
func(x*x, n/2)

Do the dry run - pretty easy to understand and complete

But there can be an edge case also -
See Striver solution to understand it (overflow int case)
//if we write the code such that we are writing myPow(something , -1 * n) to handle the negative n case - 
//we have to be careful of the edge case here - 
//because - C++ integer limits
//min: -2147483648 max: 2147483647
//if we just convert from negatiive to positive - it will overflow.

TO HANDLE IT -  just take n as long instead of int


My solution (no need to handle edge case in this way) - 

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;

        if (n == 1)
            return x;

        if (n == -1)
            return 1/x;

        double ans;

        if (n%2 != 0) {
            ans = x * myPow(x, n-1);
        }
        else {
            ans = myPow(x*x, n/2);
        }

        return ans;
    }
};
