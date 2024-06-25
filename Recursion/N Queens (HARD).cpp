Wrote this completely on my own !! Happy


Approach - 
https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=58&ab_channel=takeUforward


rules - 

each col will have a queen
each row will have a queen
no queen should attack each other

1. We try each column one by one (u can row by row as well)
2. Fill col 0 - each position - there are no existing queens so there is no attack and we can keep anywhere
3. Fill col 1 - fill this at the position where no attack is possible and call again recursively
4. Dont forget to pop back if a certain combination is not possible ..

// No need to create another full array which denotes the attacked positions

check for row and column for attack
and for diagnal attack - check for all queens who have attacked - check the method i wrote below - easy

Do a dry run on paper - subtract the diagnal (for all queens) and current positions coordinates and the absolute value of both differences
must be the same if it is a diagonal attack



class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n == 1) {
            vector<string> t;
            t.push_back("Q");
            ans.push_back(t);
            return ans;
        }

        vector<pair<int,int>> queenPositions;
        solve(ans, queenPositions, 0, n);

        return ans;


    }
    
    void solve(vector<vector<string>> &ans, vector<pair<int,int>> &queenPositions, int col, int n) {
        //we iterate the rows and place the queen wherever we can, one by one

        if (queenPositions.size() == n) { //enroll it in the answer
            vector<string> strs;
            string str;
            for (int j=0;j<n;j++) {
                str = str + ".";
            }

            for (int i=0;i<n;i++) {
                strs.push_back(str);    
            }

            for (auto itr: queenPositions) {
                int r = itr.first;
                int c = itr.second;

                strs[r][c] = 'Q';
            }

            ans.push_back(strs);
            return;
        }

        if (col == n)
            return;
        
        for (int i=0;i<n;i++) {
            //try to place it in any row but column is fixed = col

            pair<int, int> pos;
            pos.first = i;
            pos.second = col;

            bool attack = false;
            //check if this pos is being attacked by any of the existing queens
            for (auto queen: queenPositions) {
                if (queen.first == pos.first || queen.second == pos.second || diagonalAttack(pos, queen)) {
                    attack = true;
                    break;
                }
            }

            if (attack == false) { //keep this queen here at i, col
                pair<int, int> temp;
                temp.first = i;
                temp.second = col;
                queenPositions.push_back(temp);
                solve(ans, queenPositions, col+1, n);
                queenPositions.pop_back();
            }
        }
    }

    bool diagonalAttack(pair<int,int> pos, pair<int,int> queen) {
        int diff1 = pos.first - queen.first;
        int diff2 = pos.second - queen.second;
        
        if (abs(diff1) == abs(diff2))
            return true;
        
        return false;
    }
};