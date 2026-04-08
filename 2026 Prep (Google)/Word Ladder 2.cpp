https://leetcode.com/problems/word-ladder-ii/description/

In this - find out all the possible shortest Routes - and then return them as well!

Damn Hard

If the problem is Word Ladder II (where you must return every possible shortest path), you have to modify the basic BFS:

Remove the immediate return: You must finish the current "layer" entirely before stopping.

Layer-based Visited: You only mark words as "visited" after the entire level is processed. 
This allows two different Level 2 words to both point to the same Level 3 word.

Store Parents: Instead of just a bool in the visited map, you store a list of "parent" words to reconstruct the 
paths later.


UNSOLVED as of now.

