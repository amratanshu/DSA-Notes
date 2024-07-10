TOPO SORT using DFS

CONCEPT - similar to plain old cycle detection

Use visitedArray and a STACK

1. Start the dfs call from 0
2. Call dfs if visited or not ; Start putting into the stack

Intuition: In the stack - the bottom most element will be the one whose DFS is complete. (We add to stack only when dfs is complete na)

By this way, we are already making sure that deepest wale (which will be LATER in the topo sorting order) are sabse neeche in the stack.

Dfs calls jab return hone ek ek karke - tab we put 2nd deepest level in stack, then we put first deepest

sabse upar shallowest hota hai (st.top())

Screenshot is attached


