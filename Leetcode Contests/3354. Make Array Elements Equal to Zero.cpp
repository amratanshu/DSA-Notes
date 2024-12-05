3354. Make Array Elements Equal to Zero

Just do what the question says
The constraints are pretty small.

class Solution {
public:
    bool isValidSelection(int i, vector<int> nums, int dir) {
        int n = nums.size();
        while(i>=0 && i<=n-1) {
            if (nums[i] == 0) {
                if (dir) {
                    i++;
                }
                else {
                    i--;
                }
            }
            else if (nums[i] > 0) {
                nums[i]--;
                dir = 1 - dir;
                if (dir) i++;
                else i--;
            }
        }

        //check if all zeroes
        for (auto ele: nums) {
            if (ele!=0) return false;
        }
        return true;
    }

    int countValidSelections(vector<int>& nums) {
        //just do the process as mentioned.

        int ans = 0;
        for(int i=0; i<nums.size();i++) {
            if (nums[i] == 0) {
                if (isValidSelection(i, nums, 1)) ans++;
                if (isValidSelection(i, nums, 0)) ans++;
            }
        }    
        return ans;
    }
};