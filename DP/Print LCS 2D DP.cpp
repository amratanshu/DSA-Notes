https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=3

First thing which comes to mind is this solution (but it is wrong!!)
1. We'll do LCS = "";
2. In the loops which are populating dp array
if (s1[i] == s2[j])
    LCS += s1[i];

But this is wrong - because the information of max() wala case is lost in this

This will simply take all the common elements in both the strings and print them. 

This will work only when ALL THE SAME LETTERS in the two strings come in that same order.

it will work for 
abcde
bdgek

because "bed" are the common ones and they come in the same order.

But if it was somthing like ->
abcdbe
bdgek

Then we would have added to string LCS in the loop when S1[4] "b" == S2[0] "b"
We definitely dont want this because they are not part of the same subsequence. 

Hence, we have to backtrack this 2d DP array from dp[n][m] and go in the direction we 
came from - preserving the max() condition and then add to LCS wherever they are s1[i] == s2[j].

SOLUTION WITH BACKTRACK !!

This solution is based on 1-based indexing -
See LCS solution to understand this.

#include<bits/stdc++.h>

string findLCS(int n, int m,string &s1, string &s2){
	int dp[n+1][m+1];
	string lcs = "";
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else 
				dp[i][j] = max(
					dp[i-1][j],
					dp[i][j-1]
				);
		}
	}
	int i = n, j = m;
	while (i > 0 && j > 0) {
		if (s1[i-1] == s2[j-1]) {
			lcs = s1[i-1] + lcs;
			i--;
			j--;
		}
		else if (dp[i-1][j] > dp[i][j-1]) i--;
		else j--;
	}
	return lcs;
}
