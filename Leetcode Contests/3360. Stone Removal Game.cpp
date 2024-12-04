3360. Stone Removal Game

TOO EASY

class Solution {
public:
    bool canAliceWin(int n) {
        bool ans = true;
        int chance = 1;
        int s = 10;
        while(s <= n) {
            n = n - s;
            s--;
            chance = 1 - chance;
        }

        if (chance) return false;
        else return true;
    }
};