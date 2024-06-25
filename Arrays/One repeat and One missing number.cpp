One number is repeating one time and one number is missing from an array

1 to N

we can use the formula for sum of n numbers and sum of squares for n numbers here to form equations easily.

My own code ->
vector<int> Solution::repeatedNumber(const vector<int> &a) {
    
    long long actualSum = 0;
    long long actualSumSq = 0;
    
    for (int i=0;i<a.size();i++) {
        actualSum += (long long) a[i];
        actualSumSq += (long long) a[i] * (long long)a[i];        
    }
    
    long long n = a.size();
    
    long long sum = n;
    sum *= (n+1);
    sum /= 2;
    
    long long sumSq = (n*2) + 1;
    sumSq *= n+1;
    sumSq *= n;
    sumSq /= 6;
    
    long long AminusB = actualSum - sum;
    long long AsqminusBsq = actualSumSq - sumSq;
    
    long long Aplusb = AsqminusBsq/AminusB;
    
    long long A = AminusB + Aplusb;
    A = A/2;
    
    long long B = Aplusb - AminusB;
    B = B/2;
    
    vector<int> ans;
    ans.push_back((int) A);
    ans.push_back((int) B);
    return ans;
}


METHOD 2 ->
XOR SOLUTION - see striver video
https://www.youtube.com/watch?v=2D0D8HE6uak&ab_channel=takeUforward

