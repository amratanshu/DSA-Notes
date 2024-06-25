https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

DP HARD

CONCEPT : We will use Subset Equal to Sum K SOLUTION HERE ALSO!

HOW? 

Here we have to divide array into two subsets with sums having abs difference as MINIMUM;

If we divide array into two subsets of sum S1 and S2;

Then S2 = totalSum - S1;

If we want S1 and S2 to be close (abs diff should be MINIMUM) - we can start looking for 
what all S1's are actually possible..

And the best place to start from is totalSum / 2 - 
if such a sum is possible in some subset - abs difference should be 0

So basically step1 - look for subset with sum K=totalSum/2
Then look for sum K = totalSum/1 +/- 1


int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	if (arr.size() == 1) {
            return arr[0];
        }

	int sumTotal = 0;
	for (auto i: arr) {
		sumTotal+=i;
	}
	
	int k = sumTotal;
	vector<bool> curr(k+1, false);
	vector<bool> prev(k+1, false);

	
	prev[0] = true;
	curr[0] = true; //because for anything, target=0 should always be true na
	
	if (arr[0] <= k)
		prev[arr[0]] = true; //case: if we got the target at the first place only

	
	for (int i=1;i<arr.size();i++) {
		for (int j=1; j<=k; j++) {
			bool notTake = prev[j];
			bool take = false;

			if (arr[i] <= j) {
				take = prev[j-arr[i]];
			} 
			curr[j] = take || notTake;
		}
		prev = curr;
	}

	int ans = INT_MAX;
	for (int i=0; i<=sumTotal/2; i++) {
		int sum2 = sumTotal - i;
		int diff = abs(sum2 - i);

		if (prev[i])
			ans = min(ans, diff);
	}
	
	return ans;
        
}

The solution written here is not the most optimal. We can actually start looking from just totalSum/2 to totalSum and whichever we find first - is the answer kyuki vo minimum hi hoga humesha bro !

This was giving some err in LC and passing all but one case on CodingNinjas so something weird is going on idk. But just know the concept. Important !

