https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


CONCEPT - We can choose the same item multiple times. 
Slight modification of 0/1 knapsack

Note: this is not the most space optimised - I modified the curr and prev way
We can even take it down to a single vector space complexity - see knapsack to understand MORE

int unboundedKnapsack(int n, int maxWeight, vector<int> &val, vector<int> &weight){

	vector<int> prev(maxWeight + 1, 0);
	vector<int> curr(maxWeight + 1, 0);

	//dp[i][j] MEANS: index i tak, j=weight limit remaining in bag - kitni value collect kari hai max.

	for (int W=weight[0]; W<=maxWeight; W++) {
		prev[W] = (W/weight[0]) * val[0]; //can pick same item multiple times
	}

	for (int i=1;i<n;i++) {
		for (int W=0; W<=maxWeight; W++) {
			int notTake = 0 + prev[W]; //same as regular knapsack
			int take = 0;

			if (weight[i] <= W) //can pick
			{
				take = val[i] + curr[W-weight[i]];
			}

			curr[W] = max(take, notTake);
		}
		prev = curr;
	}

	return prev[maxWeight];
}