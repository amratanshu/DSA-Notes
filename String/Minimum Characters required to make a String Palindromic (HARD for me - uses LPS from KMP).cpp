This question is a HARD DP Question as well - - BUT BUT
in that ques - we were allowed to insert a new char anywhere !!

check out solution in DP folder

https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/hints/

APPROACH ->

Each index of LPS array contains the longest prefix which is also a suffix. 
Now take the string and reverse of a string and combine them with a sentinal character in between 
them and compute the LPS array of this combined string. Now take the last value of the LPS array and 
subtract it with the length of the original string, This will give us the minimum number of insertions 
required in the begining of the string .

Look at the examples - you will understand easily

Code is really easy as it is just LPS KMP code which is difficult to know.

vector<int> preprocessing(string pat) {
    int M = pat.length();

    vector<int> lps(M, 0);
    lps[0] = 0;
    int i = 1, len = 0;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else
        {
            if (len != 0) {
                len = lps[len - 1];
            } else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
int Solution::solve(string A) {
    if (A.length() == 1)
        return 0;
    
    string copyA = A;
    reverse(A.begin(), A.end());
    vector<int> lps = preprocessing(copyA + '$' + A);
    
    return A.length() - lps.back();
}