3370. Smallest Number With All Set Bits

class Solution {
public:
    int smallestNumber(int n) {
        int i = 1;
        
        while(i <= n) {
            i = i * 2;
        }
        
        return i - 1;
    }
};

