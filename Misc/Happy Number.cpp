https://leetcode.com/problems/happy-number/

I am checking if the square sum is ever being repeated

Other people's approach is also given below

My solution ->

class Solution {
public:
    bool isHappy(int n) {

        int temp = n;
        int sum = 0;
        map<int, int> m;
        while(temp) {
            int digit = temp%10;
            sum += digit * digit;
            temp = temp/10;
            if (temp == 0) {
                //restart
                if (sum == 1) return true;
                temp = sum;
                if (m.find(sum) == m.end())
                    m[sum] = 1;
                else return false;
                sum = 0;
            }
        }
        return true;
    }
};


Another method ->
https://leetcode.com/problems/happy-number/solutions/3767573/easy-java-solution-two-pointers-floyd-s-tortoise-and-hare-detailed-explanation/

Here - we are checking the same thing - whether a square is being repeated using the hare and tortoise thing

We can move the pointer quickly if we do square(square(digit))
Single movement (for the tortoise) can be done in square()

Cycle eventually toh tootegi hi - if it breaks at 1 - then we are good to go

import java.util.LinkedList;

class Solution {
    public boolean isHappy(int n) {
        
        int slow = n;
        int fast = n;
//while loop is not used here because initially slow and 
//fast pointer will be equal only, so the loop won't run.
        do {
//slow moving one step ahead and fast moving two steps ahead

            slow = square(slow);
            fast = square(square(fast));
        } while (slow != fast);

//if a cycle exists, then the number is not a happy number
//and slow will have a value other than 1

        return slow == 1;
    }
    
//Finding the square of the digits of a number

    public int square(int num) {
        
        int ans = 0;
        
        while(num > 0) {
            int remainder = num % 10;
            ans += remainder * remainder;
            num /= 10;
        }
        
        return ans;
    }
}