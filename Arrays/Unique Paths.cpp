https://www.youtube.com/watch?v=t_f0nwwdg5o&ab_channel=takeUforward

Easy 2D DP solution

Still watch the solution for PnC approach by Striver -- Most optimal

There is one more optimal solution - even better than the 2D DP solutions

Listing down the paths as strings

You can go Right - R
You can go Down - D

Your paths will look like - RRD RDR etc...

So better solution would be to complete things in this combinatorics fashion.

To go from Start To End - we must take a certain number of RIGHTS and certain number of DOWNS in the entire path


Observation 1 

Total number of directions/moves i need to take -

m-1  +  n-1 = m+n-2


Observation 2 

We have m + n - 2 number of boxes to fill m-1 Rights and n-1 Downs

So this is just a PnC combination question now - 

ANSWER => m+n-2 C m-1  OR m+2-1 C n-1


To calculate nCr - see the pascal triangle question and its striver video - optimised way