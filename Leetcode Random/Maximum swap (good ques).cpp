https://leetcode.com/problems/maximum-swap/description/?envType=company&envId=facebook&favoriteSlug=facebook-thirty-days

hint - track last occurence of each digit and then make the swap

Can we identify a pattern in the results that will help us identify the best swap? 
If we think through some examples, it can be observed that in each example the optimal swap involves 
moving the largest digit we can move forward to replace a smaller one.

To achieve this, we make two passes over the number. In the first pass, we scan from right to left to 
identify and store the largest digit we find and its position.

In the second pass, we move from left to right. Now that we know, for each position, the largest digit 
that appears after it, we check if we can make a swap. The first time we find a digit that is smaller than 
the largest one that comes after it, we swap them. Since we’re always looking for the largest possible swap, 
this guarantees that we’ll maximize the number.

My solution ->

maintain a maxTillNow..

This is not the most space optimized solution - but time complexity is best. 100% beats

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digit;

        int temp = num;
        while (temp) {
            digit.push_back(temp % 10);
            // maxi = max(maxi, temp%10);
            temp = temp / 10;
        }

        // HINT - track last occurence of each digit

        int maxi = INT_MIN;
        int maxIndex;
        vector<int> maxTillNow; // stores index of maximum element so far
        for (int i = 0; i < digit.size(); i++) {
            int d = digit[i];
            if (maxi < d) {
                maxi = d;
                maxIndex = i;
            }
            maxTillNow.push_back(maxIndex);
        }

        // move from opposite dir now
        for (int i = digit.size() - 1; i >= 0; i--) {
            if (digit[i] < digit[maxTillNow[i]]) {
                swap(digit[i], digit[maxTillNow[i]]);
                break;
            }
        }

        temp = 0;
        int power = 1;
        for (auto d : digit) {
            temp += d * power;
            power = power * 10;
        }
        return temp;
    }
};