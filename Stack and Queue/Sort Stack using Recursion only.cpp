Good recursion question and intuition 

Approach 

1. Recursive Sorting: The `sortStack` function sorts the stack by recursively removing the top element, 
sorting the remaining elements, and then inserting the removed element back in its correct position. 

2. Inserting in Sorted Order: The `insert` function places an element into its correct position in an 
already sorted stack.

Detailed Steps 

1. sortStack Function:   - If the stack is not empty, remove the top element.   - 
Recursively call `sortStack` to sort the remaining elements.   - Use the `insert` function to place
the removed element back in the sorted stack.

2. insert Function:   - If the stack is empty or the top element of the stack is less than or equal
 to the element to be inserted, push the element onto the stack.   - Otherwise, remove the top element, 
 recursively call `insert` to place the element in its correct position, and then push the removed element 
 back onto the stack.



TIME ->

Time Complexity: The time complexity is O(n^2), where n is the number of elements in the stack. 
This is because for each element, we potentially have to reinsert it back into a sorted stack of size n. 

Space Complexity: The space complexity is O(n) due to the recursion stack, 
where n is the depth of the recursion.

#include <bits/stdc++.h> 
//recursively inserts ele into the already sorted stack st - in the correct position
void insert(stack<int> &st, int ele) {
	if (st.empty()) {
		st.push(ele);
		return;
	}

	int top = st.top();

	if (top > ele) {
		st.pop();
		insert(st, ele);
		st.push(top);
		return;
	}

	else {
		st.push(ele);
		return;
	}
}

void sortStack(stack<int> &stack)
{
	
	if (stack.size() == 1)
		return;
	
	int top = stack.top();
	stack.pop();
	sortStack(stack); //remaining stack is sorted
	
	//insert the top on top of this stack now
	insert(stack, top);
}

