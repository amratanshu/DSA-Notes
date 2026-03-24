https://leetcode.com/problems/maximal-rectangle/

Watch Striver Video For Solution!


Maximal Square was easier.

Rectangle is slightly trickier.

First thought - somehow can we store the maximum streak of 1s (vertical streak AND horizontal streak)
ending at i, j --??

Would this help? (imagine traversing the 2D matrix in right down fashion like we usually do)

But here - how to form the recurrence relation using the i-1, j-1 element?


Yes our solution works. Just maintain 2 2D vectors which store the horizontal and vertical streaks.

And in the recurrence relation - no need to actually pay attention to the diagonal element. Just upper and left element
can do the job.


First Draft - Passing many test cases but failing half of them!

WRONG INTUITION !! Written below WHY!!

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (n == 1 && m == 1) {
            if (matrix[0][0] == '1') return 1;
            else return 0;
        }
        vector<vector<int>> horizontal(n, vector<int>(m, 0));
        vector<vector<int>> vertical(n, vector<int>(m, 0));

        int maxi = 0;

        // Populate first column
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == '1') {
                horizontal[i][0] = 1;
                if (i == 0) vertical[0][0] = 1;
                else vertical[i][0] = vertical[i-1][0] + 1;;
            }
        }

        // Populate first row
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == '1') {
                vertical[0][j] = 1;
                if (j == 0) horizontal[0][0] = 1;
                else horizontal[0][j] = horizontal[0][j-1] + 1;;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '1') { // Changed to '1'

                    int horizontalUpper = horizontal[i-1][j];
                    int horizontalLeft = horizontal[i][j-1];
                    int verticalUpper = vertical[i-1][j];
                    int verticalLeft = vertical[i][j-1];

                    //now we have the streaks for the upper one and left one
                    horizontal[i][j] = 1 + horizontalLeft; 
                    vertical[i][j] = 1 + verticalUpper;
                    int hstreak = min(horizontal[i][j], horizontalUpper);
                    int vstreak = min(verticalLeft, vertical[i][j]);

                    int area = hstreak * vstreak;
                    maxi = max(maxi, area);
                }
            }
        }

        return maxi;
    }
}
;



The above was failing this test case - 0 1 in the first row and nothing else.

In this case - horizontal and Vertical arrays - will also look like 0 1

but we forgot to handle the case in the 2-for-loops where i or j is zero

Correcting for this ->

1. In the first independent loops - The Populate first column and populate first row loops - handle maxi there also
because those single line streaks are also rectangles

But it still doesnt solve the problem


This is wrong because we are thinking only in terms of left and vertical streaks of 1s.

We are thinking of a local solution. The problem is - a Rectangle can maximise area using just vertical height as well

and our solution totally misses that. Our solution always looks for a triangle that includes the LEFT and UPPER elements both.

Meanwhile - the area can be maximised using just upper vertical streak or just left as well.


So if we handle that using this code -> (Still 10 test cases are failing)

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (n == 1 && m == 1) {
            if (matrix[0][0] == '1') return 1;
            else return 0;
        }
        vector<vector<int>> horizontal(n, vector<int>(m, 0));
        vector<vector<int>> vertical(n, vector<int>(m, 0));

        int maxi = 0;

        // Populate first column
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == '1') {
                horizontal[i][0] = 1;
                if (i == 0) vertical[0][0] = 1;
                else vertical[i][0] = vertical[i-1][0] + 1;;

                maxi = max(maxi, vertical[i][0]);
            }
        }

        // Populate first row
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == '1') {
                vertical[0][j] = 1;
                if (j == 0) horizontal[0][0] = 1;
                else horizontal[0][j] = horizontal[0][j-1] + 1;;

                maxi = max(maxi, horizontal[0][j]);
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '1') { // Changed to '1'

                    int horizontalUpper = horizontal[i-1][j];
                    int horizontalLeft = horizontal[i][j-1];
                    int verticalUpper = vertical[i-1][j];
                    int verticalLeft = vertical[i][j-1];

                    //now we have the streaks for the upper one and left one
                    horizontal[i][j] = 1 + horizontalLeft; 
                    vertical[i][j] = 1 + verticalUpper;
                    int hstreak = min(horizontal[i][j], horizontalUpper);
                    int vstreak = min(verticalLeft, vertical[i][j]);

                    //this is the area when we involve both the left and the upper element to make a rectangle (what if we dont?)
                    int area = hstreak * vstreak;

                    //there can be single line rectangles ending at i, j as well - lets calculate those.
                    int areaVertical = 1 + verticalUpper;
                    int areaHorizontal = 1 + horizontalLeft;
                    
                    maxi = max(maxi, area);
                    maxi = max(maxi, areaVertical);
                    maxi = max(maxi, areaHorizontal);
                }
            }
        }

        return maxi;
    }
}
;



Failing Test Case ->



[["0","0","1","0"],["0","0","1","0"],["0","0","1","0"],["0","0","1","1"],["0","1","1","1"],["0","1","1","1"],["1","1","1","1"]]



CORRECT SOLUTION ->


Using Monotonic Stack!!

Already Solved in this repository somewhere

Striver does it using monotonic stack to find area of histogram rectangle for each row

Is there a purely DP solution? 

YES - with 3 1-D DP arrays

Left Right and height Arrays

In layman's terms, for every cell (i, j), we don't just ask about the neighbor; 
we calculate the tallest possible bar ending at that cell and then determine the widest possible expansion 
(Left and Right) that this specific bar can maintain without hitting a '0'.

According to GPT ->

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();

        // height, left boundary, and right boundary arrays
        vector<int> h(m, 0);
        vector<int> l(m, 0);
        vector<int> r(m, m); // Initialize right boundary to the far right

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int cur_left = 0, cur_right = m;

            // 1. Update Height: Standard DP height accumulation
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') h[j]++;
                else h[j] = 0;
            }

            // 2. Update Left: The left boundary is the MAX of the 
            // current row's left-side '0's and the previous row's left boundary.
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    l[j] = max(l[j], cur_left);
                } else {
                    l[j] = 0; // Reset for next row
                    cur_left = j + 1;
                }
            }

            // 3. Update Right: The right boundary is the MIN of the
            // current row's right-side '0's and the previous row's right boundary.
            for (int j = m - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    r[j] = min(r[j], cur_right);
                } else {
                    r[j] = m; // Reset for next row
                    cur_right = j;
                }
            }

            // 4. Calculate Area: Now we have a stable height and a 
            // width that is guaranteed to be valid for all rows in that height.
            for (int j = 0; j < m; j++) {
                maxArea = max(maxArea, (r[j] - l[j]) * h[j]);
            }
        }

        return maxArea;
    }
};

1. Defining the Arrays (The "Clamps")h[j] (Height): The number of continuous '1's directly above column $j$. 
If you hit a '0', the height resets to 0.l[j] (Left Limit): The leftmost index this rectangle can reach. 
It is the "tightest" (largest index) left-boundary encountered across all $h[j]$ rows above it.
r[j] (Right Limit): The rightmost index this rectangle can reach. It is the "tightest" (smallest index) 
right-boundary encountered across all $h[j]$ rows above it.

2. Why $(r - l) \times h$ is a Perfect Rectangle
It is a perfect rectangle because the max and min functions act as "Inherited Constraints."
If you want to build a rectangle that is 3 units high ($h=3$), that rectangle must be valid in the current row, 
the row above it, and the row above that.If Row 1 has a '0' at index 1, the l value for that column becomes 
2.Even if the current Row 3 is all '1's, the l value remains 2 because it inherited the "bottleneck" from Row 1.
The formula calculates the area of the intersection of all horizontal streaks within that height.


Can we Alter our earlier solution and do something about it?
NO!


