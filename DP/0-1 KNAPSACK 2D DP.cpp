https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

CONCEPT - similar - pick and not pick problem


1. Form a recurrence relation in your mind where parameters are (index, weightLimitRemaining in bag)
2. The base cases will be for index==0 - if we can pick or not pick
3. Choose max(pick, nonPick)
4. Memoize it so that dp[i][j]: MEANS: index i tak, j=weight limit remaining in bag - kitni value collect kari hai max.
5. Space optimize using a single prev and curr

CATCH - this below solution is space optimized to use prev and curr - two 1D arrays
BUT WE CAN OPTIMISE IT EVEN MORE in this case !!
Solution shown right after first solution. !!


#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> val, int n, int maxWeight) 
{
	// Write your code here
	vector<int> prev(maxWeight + 1, 0);
	vector<int> curr(maxWeight + 1, 0);

	//dp[i][j] MEANS: index i tak, j=weight limit remaining in bag - kitni value collect kari hai max.

	for (int W=weight[0]; W<=maxWeight; W++) {
		prev[W] = val[0];
	}

	for (int i=1;i<n;i++) {
		for (int W=0; W<=maxWeight; W++) {
			int notTake = 0 + prev[W];
			int take = INT_MIN;

			if (weight[i] <= W) //can pick
			{
				take = val[i] + prev[W-weight[i]];
			}

			curr[W] = max(take, notTake);
		}
		prev = curr;
	}

	return prev[maxWeight];
}



MORE SPACE OPTIMIZED SOLUTION :

If you observe carefully - 
curr[W] is always populated using prev [W] and prev[W-something] 

So - for curr[W] - prev[W] ke peeche wale elements hi chahie. W ke upar wala index kabhi nahi chahie.

So why even save it?

We can write prev[W] in place because peeche walo ka use ho raha hai. Bas ulta traverse kar lenge loop ko!!
W = 0 to maxWeight NO 
W = maxWeight to 0 YES !!!

BEST SOLUTION:::::

#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> val, int n, int maxWeight) 
{
	// Write your code here
	vector<int> prev(maxWeight + 1, 0);
	// vector<int> curr(maxWeight + 1, 0);

	//dp[i][j] MEANS: index i tak, j=weight limit remaining in bag - kitni value collect kari hai max.

	for (int W=weight[0]; W<=maxWeight; W++) {
		prev[W] = val[0];
	}

	for (int i=1;i<n;i++) {
		for (int W=maxWeight; W>=0; W--) {
			int notTake = 0 + prev[W];
			int take = INT_MIN;

			if (weight[i] <= W) //can pick
			{
				take = val[i] + prev[W-weight[i]];
			}

			prev[W] = max(take, notTake);
		}
	}

	return prev[maxWeight];
}