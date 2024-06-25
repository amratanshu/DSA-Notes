https://www.naukri.com/code360/problems/max-of-min_982935?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=SUBMISSION

CONCEPT -

At any element, if you know the leftSmaller and rightSmaller - 
then in this whole range (windows of size 1, 2, 3 to rightS - leftS (not included)) => will have the current element
as the minimum

So we can just keep moving forward this way..
and 

General formula 
at any ele i - 
windows of sizes 1 to (rightSm - leftSm - 1)  will have minimum element as = A[i]

go and populate this in the respective window sizes - if this is max - replace it !



MY CODE DOESNT HAVE THIS OPTIMISATION but --
Another optimisation --
we dont need to mark it for all ranges 1 to FORMULA (see the innert most for loop)

If we just mark it on size = X (highest window size) for each element

Then, in the end (after the main for loop, just before returning ans) - we can just run something like this ->
 for (int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

iska intuition - https://www.youtube.com/watch?v=DCU3T-XqG_s&ab_channel=CoderArmy 
timestamp - 1:40:28

My Solution ->

#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    stack<int> st;
    vector<int> ans(n, INT_MIN);

    //we're just calculating prevSmaller and nextSmaller 
    //in a single pass (have already done this ques)
    //for an ele - prevSmall to nextSmall is basically the range of window (size wise) where 
    //this ele is the minimum
    for (int i=0;i<=n;i++) {
        while(!st.empty() && (i == n || a[st.top()] >= a[i])) {
            //this below element is the min element in the window size 
            //range [1 to (nextSmall - prevSmall - 1)] both inclusive
            
            int eleIndex = st.top();
            int nextSmaller = i; //the current element index is the nextSmaller for stack top
            st.pop();

            int range;
            if (st.empty())
                range = nextSmaller;
            else
                range = nextSmaller - st.top() - 1;

            for (int windowSize=1; windowSize<=range; windowSize++) {
                ans[windowSize-1] = max(ans[windowSize-1], a[eleIndex]);
            }
        }

        st.push(i);
    }
    return ans;
}