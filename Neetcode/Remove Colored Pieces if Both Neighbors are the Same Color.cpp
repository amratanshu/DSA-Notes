https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/

This is just a pointer arithmetic question

you have to find the number of moves both players have got

Check the comment in this code to understand more

class Solution {
public:
    bool winnerOfGame(string colors) {
        // just calculate the number of moves each player has. because it does
        // not depend on what the other player does. if there is AABAAAB - the
        // middle B can never be removed as it will always be close to the A's
        // on its left and right same goes for that left A and right A (from
        // that center B) - it cannot be removed!

        int a = 0; // alice moves
        int b = 0; // bob moves

        int consecutive = 1;

        char prev = colors[0];
        int i = 1;
        while (i < colors.size()) {
            if (colors[i] == prev) {
                consecutive++;
            } else {
                // if this was a streak of A's
                if (consecutive > 2) {
                    if (prev == 'A') {
                        a += consecutive - 2;
                    }
                    // if this was a streak of B's
                    else {
                        b += consecutive - 2;
                    }
                }

                prev = colors[i];
                consecutive = 1;
            }
            i++;
        }

        // handle if there was a streak at the end of the string ->
        if (consecutive > 2) {
            if (prev == 'A') {
                a += consecutive - 2;
            }
            // if this was a streak of B's
            else {
                b += consecutive - 2;
            }
        }
        cout << a << endl;
        cout << b;
        if (a == 0)
            return false;
        if (a > b)
            return true;
        else
            return false;
    }
};

BETTER and readable code ->

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();

        if (n < 3) return false; // If the length of the string is less than 3, Bob wins.

        int a = 0; // Initialize the count of consecutive triplets for A
        int b = 0; // Initialize the count of consecutive triplets for B

        // Iterate through the string starting from the second character
        for (int i = 1; i < n - 1; i++) {
            // Check if there is a consecutive triplet (e.g., "AAA" or "BBB")
            if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1]) {
                if (colors[i] == 'A') a++; // Count consecutive triplets for A
                else if (colors[i] == 'B') b++; // Count consecutive triplets for B
            }
        }

        return a > b; // Alice wins if she has more consecutive triplets than Bob
    }
};

