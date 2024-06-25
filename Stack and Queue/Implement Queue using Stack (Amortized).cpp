https://www.youtube.com/watch?v=3Et9MrMc02A&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=76&ab_channel=takeUforward

Watch striver video to understand amortized

In most cases - you are just using 2nd stack (output) to do a pop and top

When it is empty - you transfer complete 1st stack eles to 2nd stack (input --> output) - and this takes time O(N)

But other than that - most times we do just single element removal from 2nd stack - so 

Total TC is = O(1) amortized

code - 

#include <bits/stdc++.h>

using namespace std;

class MyQueue {
  public:
    stack < int > input, output;
  /** Initialize your data structure here. */
  MyQueue() {

  }

  /** Push element x to the back of queue. */
  void push(int x) {
    cout << "The element pushed is " << x << endl;
    input.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    // shift input to output 
    if (output.empty())
      while (input.size())
        output.push(input.top()), input.pop();

    int x = output.top();
    output.pop();
    return x;
  }

  /** Get the front element. */
  int peek() {
    // shift input to output 
    if (output.empty())
      while (input.size())
        output.push(input.top()), input.pop();
    return output.top();
  }

  bool empty() {
    return (input.empty() && output.empty());
  }
};