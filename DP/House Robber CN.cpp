HOUSE ROBBER 2
https://www.codingninjas.com/studio/problems/house-robber-ii_839733?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

CONCEPT - pick and not pick - EXACTLY similar to max no of non adj elements !!

We cant pick first and last house together ever !! because houses are in a circle and adjacent houses not allowed !!

1. pick first house + find ans for remaining houses
2. pick last house + find ans for remaining houses

to find ans for remaining houses - follow the approach from max-sum-of-non-adj-elements questions only - there we were doing the exact same thing... max hi nikal rahe the

FINAL ANS = Max (1, 2 )

In this code - make sure long long int - 10^ whatever is being given.f
