https://neetcode.io/problems/count-squares

easy solution - just do it on paper and you will get it.

This is my own solution -> a better and smaller working solution is just below this ->

class CountSquares {
public:
    map<pair<int, int>, int> m;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        m[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        //check in all 4 directions across all the points possible (0 to 1000 range)

        int x = point[0];
        int y = point[1];
        int ans = 0;

        for(int dist=1; dist<=1000; dist++) {
            //right up
            if (y+dist <= 1000 && x+dist <= 1000) {
                bool a = m.find({x+dist, y}) != m.end();
                bool b = m.find({x+dist, y+dist}) != m.end();
                bool c = m.find({x, y+dist}) != m.end();
                if (a && b && c) {
                    ans += m[{x+dist, y}] * m[{x+dist, y+dist}] * m[{x, y+dist}];
                }
            }

            //left up
            if (y+dist <= 1000 && x-dist >= 0) {
                bool a = m.find({x-dist, y}) != m.end();
                bool b = m.find({x-dist, y+dist}) != m.end();
                bool c = m.find({x, y+dist}) != m.end();
                if (a && b && c) {
                    ans += m[{x-dist, y}] * m[{x-dist, y+dist}] * m[{x, y+dist}];
                }
            }
            
            //left down
            if (y-dist >= 0 && x-dist >= 0) {
                bool a = m.find({x-dist, y}) != m.end();
                bool b = m.find({x-dist, y-dist}) != m.end();
                bool c = m.find({x, y-dist}) != m.end();
                if (a && b && c) {
                    ans += m[{x-dist, y}] * m[{x-dist, y-dist}] * m[{x, y-dist}];
                }
            }

            //right down
            if (y-dist >= 0 && x+dist <= 1000) {
                bool a = m.find({x+dist, y}) != m.end();
                bool b = m.find({x+dist, y-dist}) != m.end();
                bool c = m.find({x, y-dist}) != m.end();
                if (a && b && c) {
                    ans += m[{x+dist, y}] * m[{x+dist, y-dist}] * m[{x, y-dist}];
                }
            }
        }
        return ans;
    }
};


BETTER SOLUTION ->

class CountSquares {
    unordered_map<int, unordered_map<int, int>> ptsCount;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        ptsCount[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int res = 0;
        int x1 = point[0], y1 = point[1];

        for (auto &[y2, cnt] : ptsCount[x1]) {
            int side = y2 - y1;
            if (side == 0) continue;

            int x3 = x1 + side, x4 = x1 - side;
            res += cnt * ptsCount[x3][y1] * ptsCount[x3][y2];
            res += cnt * ptsCount[x4][y1] * ptsCount[x4][y2];
        }

        return res;
    }
};