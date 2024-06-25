CONCEPT - 1D DP 
https://www.codingninjas.com/studio/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

EQN: Dn = min (Dn-1 + x, Dn-2 + y);


#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.

    if (n==1)
        return 0; //no energy spent na

    if (n==2) //1st step to here is the only jump possible
        return heights[1] - heights[0] > 0? heights[1] - heights[0]: heights[0] - heights[1];

    int prev = heights[1] - heights[0] > 0? heights[1] - heights[0]: heights[0] - heights[1];
    int prevprev = 0;

    int ans;
    for (int i=2; i<n; i++)
    {
        int energy1 = heights[i] - heights[i-1];
        int energy2 = heights[i] - heights[i-2];
        if (energy1 < 0)
            energy1 = energy1 * -1;
        if (energy2 < 0)
            energy2 = energy2 * -1;

        ans = min(prev + energy1, prevprev + energy2);
        prevprev = prev;
        prev = ans;
        
    }
    return ans;

}

}