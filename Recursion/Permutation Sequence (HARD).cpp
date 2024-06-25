https://leetcode.com/problems/permutation-sequence/

This solution just nails it in explanation ->
https://leetcode.com/problems/permutation-sequence/solutions/22507/explain-like-i-m-five-java-solution-in-o-n

say n = 4, you have {1, 2, 3, 4}

If you were to list out all the permutations you have

1 + (permutations of 2, 3, 4)

2 + (permutations of 1, 3, 4)

3 + (permutations of 1, 2, 4)

4 + (permutations of 1, 2, 3)

this recursive solution gives us the permutations in a sorted manner only.

We know how to calculate the number of permutations of n numbers... n! So each of those with 
permutations of 3 numbers means there are 6 possible permutations. 
Meaning there would be a total of 24 permutations in this particular one. 
So if you were to look for the (k = 14) 14th permutation, it would be in the

3 + (permutations of 1, 2, 4) subset.

...

https://takeuforward.org/data-structure/find-k-th-permutation-sequence/ -

This has the recursion solution as well as the most optimal solution - where we just find the Kth one directly by
figuring out its position using some basic mathematics.

Most optimal solution - by striver - 

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        for (int i = 1; i < n; i++) {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";
        k = k - 1;
        while (true) {
            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            if (numbers.size() == 0) {
                break;
            }

            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};

