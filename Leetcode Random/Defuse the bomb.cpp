https://leetcode.com/problems/defuse-the-bomb/description/?envType=daily-question&envId=2024-11-18

Just do brute force
Constraints are very small so this can be solved in whatever time complexity possible.

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0) {
            return result;
        }

        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                int count = 0;
                int j = (i + 1) % n;
                while (count < k) {
                    sum += code[j];
                    j = (j + 1) % n;
                    count++;
                }
                result[i] = sum;
            }
        } else {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                int count = 0;
                int j = (i - 1 + n) % n;
                while (count < abs(k)) {
                    sum += code[j];
                    j = (j - 1 + n) % n;
                    count++;
                }
                result[i] = sum;
            }
        }

        return result;
    }
};