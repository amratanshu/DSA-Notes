Your natural intuition for this will be correct

We have to traverse from the right and keep removing until st.top() is lesser..

It seems like O(N^2) because of inside loop but try to understand how many times does the inner loop runs

See striver video for better explaination

https://www.youtube.com/watch?v=Du881K7Jtk8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=76&ab_channel=takeUforward

Overall - the while loop will execute by N times.

It wont be N every time 
  
Hence O (n + n) is the general complexity

In this ques - we just had to check the next greater element to the right side
But there can be another variant of this question --

What if - for all elements - if we dont find the next greatest on the right side - we also have to start checking
on the left of the element... starting with 0 index to this element

Basically - circular array

To solve this - we have to run the exact same algorithm but imagine a copy of the same array just after this array

So the ans for the last eleent a[n-1] will not always be -1. It will search in the imaginary array on the right as well

for Circular array - run the loop from 0 to 2n-1 and - for every i - do modulo n

So for 6th element - index = 5 -> modulo 5 means - it will check in A[0] - ..copy formed



class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        vector<int> ans;

        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                m[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        while (!s.empty()) {
            m[s.top()] = -1;
            s.pop();
        }

        for (int num : nums1) {
            ans.push_back(m[num]);
        }

        return ans;
    }
};