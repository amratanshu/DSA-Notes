https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

Recurrence Relation formation: 
f(index, sizeOfRodRemaining) => returns the maximum price we can sell of at.

base case for this:
1. if (sizeOfRodRemaining==0) return 0; //because kuch bech hi nahi sakte anymore
2. if (index==0) return sizeOfRodRemaining * price[index]; -> index=0 matlab rod cut ka size=1
we can sell of sizeOfRodRemaining/1 times. Hence this value

notTake = f(index-1, S) -- obvious
take = f(index, S - (index+1) -- index bceause we can sell this same rod piece MULTIPLE TIMES - concept used a lot of times so far


int cutRod(vector<int> &price, int n)
{
	// Write your code here.

	//we have optimised a dp[index+1][sizeOfRodRemaining+1]
	vector<int> prev(n+1, 0); //this base prev is for dp[1][:]
	vector<int> curr(n+1, 0);

	// prev[0] = 0; //assigning this base case is redundant, already 0
	for (int sizeOfRodRemaining = 1;sizeOfRodRemaining<=n;sizeOfRodRemaining++) {
		prev[sizeOfRodRemaining] = sizeOfRodRemaining*price[0];
	}

	for (int index=1; index<=n;index++) {
		for (int sizeOfRodRemaining=0; sizeOfRodRemaining<=n; sizeOfRodRemaining++) {
			int notTake = prev[sizeOfRodRemaining];

			int take = INT_MIN;
			if (sizeOfRodRemaining >= index+1) //because for i=0, rodsize is 1 na
				take = price[index] + curr[sizeOfRodRemaining - (index+1)];
			curr[sizeOfRodRemaining] = max(take, notTake);
		}
		prev = curr;
	}

	return curr[n];
}

