https://leetcode.com/problems/champagne-tower/description/?envType=company&envId=google&favoriteSlug=google-thirty-days

First thought - the number of "influxes" for a particular glass - is given by PASCAL TRIANGLE Numbers simply.

Can we do something with this information?

We can actually.

When all glasses in row i are full -> no of cups poured = (i * (i+1) )/ 2  --- Sum of natural nos until row number.

3rd row total poured -> 6
4th row total poured -> 10

Eg - in the 4th row -> pascal triangle -> 1 3 3 1 -> these numbers are actually the ratio at which speed the glasses
will be filled.

1/10, 3/10, 3/10 and 1/10 individually.


NOTE - THIS INTUITION IS INCORRECT PARTIALLY.

WHY? Because the middle glasses fill up quicker and might overflow as well before all the other glasses in the same 
row have been filled.

The "Center-Out" Flow
Champagne doesnt wait for a whole row to be ready. It flows like a fountain. 
Because the middle glasses have two parents pouring into them, they receive liquid much faster than the
 edge glasses, which only have one parent.


Hence our intuition was wrong!




Now -> how to solve this?

Use the "Excess" concept

If the total pour had been P, the first glass will take 1.0, then P - 1.0 will overflow into two glasses below it

Each of them will have (P-1.0) / 2.0 -> then they will also start overflowing into the two below them.

Like this -> start calculating stuff using a DP like the Pascal Triangle.

So basically - for every i, j glass 

There is some liquid incoming - INC 
Outgoing is -> (INC - 1)

This outgoing is divided into neeche wale dono equally -> so (i+1, j) and (i+1, j+1) Get (INC-1)/2.0

Using this information - solve this using DP


Code outline is simple ->

double excess;
        dp[0][0] = (double)poured;
        for(int i=0; i<query_row; i++) {
            for (int j=0; j<=i; j++) {
                excess = dp[i][j] - 1.0;
                dp[i+1][j] += excess/2.0;
                dp[i+1][j+1] += excess/2.0;
            }
        }

But there is a catch -> 
The value of dp[i][j] -> shows the amount of total influx into a glass

While returning - if that influx is greater than 1 - just return 1 (because the glass will be full right)

double excess;
        dp[0][0] = (double)poured;
        for(int i=0; i<query_row; i++) {
            for (int j=0; j<=i; j++) {
                excess = dp[i][j] - 1.0;
                dp[i+1][j] += excess/2.0;
                dp[i+1][j+1] += excess/2.0;
            }
        }
        return dp[query_row][query_glass] > 1.0? 1.0: dp[query_row][query_glass];
    }


This gives right ans for most test cases

But we have missed some edge cases again I think. 

For poured 25, query row 6, query glass 1 ==> output is going NEGATIVE???


CATCH -> in the line excess = dp[i][j] - 1.0; --> CHECK TOH KAR IF IT IS GREATER THAN 1.0 bc!!!
Tab hi toh Excess hoga

SOLUTION ->

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        vector<vector<double>> dp(101, vector<double>(101, 0.0));
        // handle edge cases here? if (poured < 1.0)

        double excess;
        dp[0][0] = (double)poured;
        for (int i = 0; i < query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[i][j] > 1.0) {
                    excess = dp[i][j] - 1.0;
                    dp[i + 1][j] += excess / 2.0;
                    dp[i + 1][j + 1] += excess / 2.0;
                }
            }
        }
        return dp[query_row][query_glass] > 1.0 ? 1.0
                                                : dp[query_row][query_glass];
    }
};


More Efficient Space Suggestions:
You can optimize the space to a single array by updating values in reverse or using
two rows to store only the previous level data.

