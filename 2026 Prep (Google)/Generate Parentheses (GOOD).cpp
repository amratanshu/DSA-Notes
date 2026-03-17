https://leetcode.com/problems/generate-parentheses/description/?envType=company&envId=google&favoriteSlug=google-three-months

DP on String Concatenation!!

Divide into smaller subproblems

Total len of string to be generated -> 2n

F(n) would be concat of F(0) + F(n)

F(n-1) would be concat of F(1) + F(n-1)

F(n-2) would be concat of F(2) + F(n-2)

Here repetetive calculations will take place and THIS would solve nothing - because in the recurrence relation - N is depending on N!!!



My Thought -> for F(N) -> The ans would be 
"(" + F(n-1) + ")" 
AND
"()" + F(n-1) 
AND
F(n-1) + "()"


But the above GIVES us Repeats! Try out with F(2) - u will realise ()() is being repeated





How can we make N depend on N-1 or something? - for DIVIDE AND CONQUER

SOLUTION: 

F(N) ->

"(" + F(0) + ")" + F(n-1)       ......              "(" + F(n-1) + ")" + F(0)


Lets try on F(3)

"(" + F(0) + ")" + F(2)       "(" + F(1) + ")" + F(1)              "(" + F(2) + ")" + F(0)


Here - F(0) is "" and F(1) is "()" and F(2) is "(())", "()()"



Lets write the solution now -->

Recursive Divide and Conquer ->



class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        if (n == 0) {
            return std::vector<std::string>{""};
        }
        std::vector<std::string> answer;
        for (int leftCount = 0; leftCount < n; ++leftCount) {
            auto leftStrings = generateParenthesis(leftCount);
            auto rightStrings = generateParenthesis(n - 1 - leftCount);
            for (const auto& leftString : leftStrings) {
                for (const auto& rightString : rightStrings) {
                    answer.push_back("(" + leftString + ")" + rightString);
                }
            }
        }
        return answer;
    }
};