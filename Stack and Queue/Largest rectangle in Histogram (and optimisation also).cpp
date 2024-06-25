Concept is good but simple at the same time

For every A[i] - if we select this as part of our rectangle - the largest rectangle would go from
(leftSmaller to rightSmaller element)

leftSmaller - the element just smaller than A[i] on the left side of the array (-1 if none)
rightSmaller - the element just smaller than A[i] on the right side of the array (-1 if none)

If we calculate it for every i - then O(n^2)

But to optimise - we will use a monotonic stack to populate leftSmaller and rightSmaller for all the elements in the array

We have done this in the NearestSmaller element question already

Use the formula every time -
for each ele - 
(rightSmaller - leftSmaller  - 1) * A[i]  --
and calculate the max area possible

But this requires multiple O(N) passes over the array

2 O(N) passes for creating rightSmaller
2 O(N) passes for creating leftSmaller
1 O(N) final pass to calculate the maximum

Solution with - O(5N) -- but this can optimised further - solution given below this one

My solution ->

class Solution {
public:
    int largestRectangleArea(vector<int>& A) {

        stack<pair<int, int>> st;
        vector<int> leftSmaller;
    
        //remember - we dont have to store the leftSmaller element. We have to store the leftSmaller element ka index

        //hence - in stack - we are storing (ele value, index) ka pair
        st.push({A[0], 0});
        leftSmaller.push_back(-1);
        for (int i = 1; i < A.size(); i++) {
            while (!st.empty() && st.top().first >= A[i]) {
                st.pop();
            }

            if (st.empty()) {
                leftSmaller.push_back(-1);
                st.push({A[i], i});
                continue;
            }

            if (st.top().first < A[i]) {
                leftSmaller.push_back(st.top().second);
                st.push({A[i], i});
            }
        }

        //TODO
        //exact same logic as above - just i is reversed as we are traversing from the right !!
        //i know - redundant code - can be removed

        vector<int> rightSmaller(A.size(), -1);
        st = stack<pair<int, int>>(); //clearing the stack by assigning to a new stack - one of many ways
        st.push({A.back(), A.size()-1});
        for(int i=A.size()-2;i>=0;i--) {
            while (!st.empty() && st.top().first >= A[i]) {
                st.pop();
            }

            if (st.empty()) {
                rightSmaller[i] = -1;
                st.push({A[i], i});
                continue;
            }

            if (st.top().first < A[i]) {
                rightSmaller[i] = st.top().second;
                st.push({A[i], i});
            }
        }

        //now traverse A and at each step - use the formula to calculate max area
        //formula - Area = (rightSmaller - leftSmaller) * A[i]
        int area = INT_MIN;
        
        for (int i=0;i<A.size();i++) {
            int right = rightSmaller[i] == -1? A.size(): rightSmaller[i];
            int left = leftSmaller[i];

            int formula = (right - left - 1)*A[i];
            if (formula > area)
                area = formula;
        }

        return area;

    }
};




Most optimal - single pass O(N) solution

https://www.youtube.com/watch?v=jC_cWLy7jSI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=81&ab_channel=takeUforward

Just start the loop as if you are calculating the leftSmaller 

While the loop is running - you will see that at any moment - at an ele i

The stack contains elements in a linearly increasing fashion

if A[i] > st.top - just push it and move ahead

if A[i] < st.top --
The elements of the stack - are nothing but leftSmaller of the current element
Which in turn means - for those elements - a[i] is the rightSmaller

So = ek ek karke un elements ko pop karo - and pop karne ke pehle do your computation using that formula

if the stack contains 1 5 6 (6 being the top) and A[i] is 2

THen - 6 wale element ka rightSmaller is 2 and leftSmaller is 5 - calculate area for it.
Then pop.
THen 5 wale element ka rightSmaller is still 2 and leftSmaller is 1...

solve like this

Good concept

Very small code only 6-7 lines


//o to n => n is included because n-1 wale element ka tab hi calcualte hoga (for the n-1th element - the leftSmaller
//will be at the stack top and 
//its right smaller will be index=n wala element which doesn't exist..)

#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    int largestRectangleArea(vector < int > & histo) {
      stack < int > st;
      int maxA = 0;
      int n = histo.size();
      //o to n - n is included because n-1 wale element ka tab hi calcualte hoga (for the n-1th element - the leftSmaller
      //will be at the stack top and 
      //its right smaller will be index=n wala element which doesn't exist..)
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          int height = histo[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }
};