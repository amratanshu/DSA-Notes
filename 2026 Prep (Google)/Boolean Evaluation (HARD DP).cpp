https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
here we are not given with parenthesis and have to find the number of ways the expr evaluates to true.

Recursive Solution

This is also similar to Partition DP - just partition at the operators & | XOR

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;
int solve(int i, int j, bool wantTrue, string &exp) {
    if (i > j) return 0;

    if (i == j) {
        if (wantTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    int count = 0;
    for (int k=i+1; k<=j-1; k = k+2) {
        //we want to find the operands and partition at them
        // if (exp[k] != '|' && exp[k] != '&' && exp[k] != '^') continue;

        int leftTrue = solve(i, k-1, true, exp);
        int leftFalse = solve(i, k-1, false, exp);
        int rightTrue = solve(k+1, j, true, exp);
        int rightFalse = solve(k+1, j, false, exp);

        if (exp[k] == '&') {
            if (wantTrue) 
                count += leftTrue * rightTrue;
            else 
                count += leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse;
        }
        else
        if (exp[k] == '|') {
            if (wantTrue) {
                count += leftTrue * rightFalse + leftFalse * rightTrue + leftTrue * rightTrue;
            }
            else 
                count += leftFalse * rightFalse;
        }
        else
        if (exp[k] == '^') {
            if (wantTrue) {
                count += leftTrue * rightFalse + leftFalse * rightTrue;
            }
            else 
                count += leftTrue * rightTrue + leftFalse * rightFalse;
        }
    }    
    return count;
}

int evaluateExp(string & exp) {
    return solve(0, exp.length()-1, true, exp);
}


This can easily be memoized. But we can further reduce the number of calls for this.

Here - we are calculation on the basis on wantTrue - and it internally calculates for the no of expressions returning 
false as well. If we return both of them as a pair in one go - that will reduce the number of calls.


SOlution ->



struct Ways {
    long long T;
    long long F;
};

Ways solve(int i, int j, string &exp) {
    if (i > j) return {0, 0};
    if (i == j) {
        if (exp[i] == 'T') return {1, 0};
        else return {0, 1};
    }

    Ways ans = {0, 0};

    for (int k = i + 1; k <= j - 1; k += 2) {
        Ways left = solve(i, k - 1, exp);
        Ways right = solve(k + 1, j, exp);

        long long lT = left.T % mod, lF = left.F % mod;
        long long rT = right.T % mod, rF = right.F % mod;

        if (exp[k] == '&') {
            ans.T = (ans.T + (lT * rT)) % mod;
            ans.F = (ans.F + (lT * rF) + (lF * rT) + (lF * rF)) % mod;
        } 
        else if (exp[k] == '|') {
            ans.T = (ans.T + (lT * rF) + (lF * rT) + (lT * rT)) % mod;
            ans.F = (ans.F + (lF * rF)) % mod;
        } 
        else if (exp[k] == '^') {
            ans.T = (ans.T + (lT * rF) + (lF * rT)) % mod;
            ans.F = (ans.F + (lT * rT) + (lF * rF)) % mod;
        }
    }
    return ans;
}