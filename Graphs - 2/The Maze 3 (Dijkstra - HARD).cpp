https://leetcode.com/problems/the-maze-iii/

Difficult question but do it piece wise 

Points to node - 
1. write code on top of maze 2 ka dijkstra
2. see that we dont always have to travel till we hit a wall. If we hit the hole first - then the ball will
be pocketed and stay there!

Couldnt solve it yet !

My code till now ->

WRONG in a few cases -- find out why --

Chat gpt answer on why this code is wrong ->

The solution has a few issues that need to be addressed:

1. Initialization Check for Destination: The condition if (maze[destination[0]][destination[1]]) 
return "impossible"; should actually check if the destination is an open space. It should be if (maze[destination[0]][destination[1]] == 1) return "impossible";.

2. Using set with Non-Unique Elements: The set<pair<int, pair<int, int>>> s; may have non-unique distance values causing issues. Using priority_queue can ensure the smallest distance is always processed first.

3. Storing Previous Node: The parentMap needs to store previous nodes accurately to reconstruct the path.

4. Direction Mapping Outside Loop: Mapping directions to characters should be outside the while loop to avoid repeated initialization.

5. Handling Equal Distance with Lexicographical Order: To handle cases where multiple shortest paths exist, you need to update parentMap only if the new path is shorter or the same length but lexicographically smaller.

class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze[destination[0]][destination[1]]) return "impossible";

        int m = maze.size();
        int n = maze[0].size();
        // vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        map<pair<int, int>, int> dist;
        map<pair<int, int>, pair<char, pair<int, int>>> parentMap; //key: node ; value - parent node and direction: {"L", {x, y}}
        dist[{start[0], start[1]}] = 0;
        set<pair<int, pair<int, int>>> s; //distance, x index, y index
        s.insert({0, {start[0], start[1]}});
        while(!s.empty()) {
            int d1 = (*s.begin()).first;
            int i = (*s.begin()).second.first;
            int j = (*s.begin()).second.second;
            s.erase(s.begin());
            vector<vector<int>> directions = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
            map<vector<int>, char> directionToChar;
            directionToChar[directions[0]] = 'd';
            directionToChar[directions[1]] = 'l';
            directionToChar[directions[2]] = 'r';
            directionToChar[directions[3]] = 'u';
            // reverse(directions.begin(), directions.end());
            
            for (auto dir : directions) {
                int x = i;
                int y = j;
                int travel = 0;
                
                //out of bounds check
                while (x + dir[0] >= 0 && x + dir[0] < m && y + dir[1] >= 0 && y + dir[1] < n && maze[x + dir[0]][y + dir[1]] == 0) {
                    x += dir[0];
                    y += dir[1];
                    travel ++;
                    //if this x, y is the hole - we have in fact, the ball will be pocketed!
                    if (x == destination[0] && y == destination[1]) {
                        break;
                    }
                    
                }

                // vector<int> vec {x, y}; //stopped at this index
                if (dist.find({x, y}) == dist.end() || d1 + travel < dist[{x, y}]) {
                    //if this is not the hole - this is a wall and we can insert this and travel further somewhere
                    if (!(x == destination[0] && y == destination[1])) {
                        s.insert({d1 + travel, {x, y}});
                    }
                    dist[{x, y}] = d1 + travel;
                    parentMap[{x, y}] = {directionToChar[dir], {i, j}};
                }
            }
        }

        if (dist.find({destination[0], destination[1]}) == dist.end()) return "impossible";
        
        // return to_string(dist[{destination[0], destination[1]}]);
        
        //now backtrack the path using the parentMap
        string ans = "";
        int a = destination[0], b = destination[1];
        while(parentMap.find({a, b}) != parentMap.end()) {
            ans.push_back(parentMap[{a, b}].first);
            int p = parentMap[{a, b}].second.first;
            int q = parentMap[{a, b}].second.second;
            a = p;
            b = q;
        }
        reverse(ans.begin(), ans.end());
        return ans;

        
    }
};


Working solution - by chat gpt ->

This one uses PQ. There is another solution after this that uses SET !

class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze[destination[0]][destination[1]] == 1) return "impossible";

        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<string>> path(m, vector<string>(n, ""));
        dist[start[0]][start[1]] = 0;
        
        priority_queue<tuple<int, int, int, string>, vector<tuple<int, int, int, string>>, greater<tuple<int, int, int, string>>> pq;
        pq.push({0, start[0], start[1], ""});
        
        vector<vector<int>> directions = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
        vector<char> dirChar = {'d', 'l', 'r', 'u'};
        
        while (!pq.empty()) {
            auto [d1, x, y, p] = pq.top();
            pq.pop();
            
            if (x == destination[0] && y == destination[1]) {
                return p;
            }
            
            for (int k = 0; k < 4; ++k) {
                int i = x, j = y, travel = 0;
                
                while (i + directions[k][0] >= 0 && i + directions[k][0] < m && j + directions[k][1] >= 0 && j + directions[k][1] < n && maze[i + directions[k][0]][j + directions[k][1]] == 0) {
                    i += directions[k][0];
                    j += directions[k][1];
                    travel++;
                    if (i == destination[0] && j == destination[1]) break;
                }

                string newPath = p + dirChar[k];
                if (dist[i][j] > d1 + travel || (dist[i][j] == d1 + travel && path[i][j] > newPath)) {
                    dist[i][j] = d1 + travel;
                    path[i][j] = newPath;
                    pq.push({dist[i][j], i, j, newPath});
                }
            }
        }

        return "impossible";
    }
};




SET SOLUTION ->

class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze[destination[0]][destination[1]] == 1) return "impossible";

        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<string>> path(m, vector<string>(n, ""));
        dist[start[0]][start[1]] = 0;
        
        set<tuple<int, int, int, string>> s;
        s.insert({0, start[0], start[1], ""});
        
        vector<vector<int>> directions = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
        vector<char> dirChar = {'d', 'l', 'r', 'u'};
        
        while (!s.empty()) {
            auto [d1, x, y, p] = *s.begin();
            s.erase(s.begin());
            
            if (x == destination[0] && y == destination[1]) {
                return p;
            }
            
            for (int k = 0; k < 4; ++k) {
                int i = x, j = y, travel = 0;
                
                while (i + directions[k][0] >= 0 && i + directions[k][0] < m && j + directions[k][1] >= 0 && j + directions[k][1] < n && maze[i + directions[k][0]][j + directions[k][1]] == 0) {
                    i += directions[k][0];
                    j += directions[k][1];
                    travel++;
                    if (i == destination[0] && j == destination[1]) break;
                }

                string newPath = p + dirChar[k];
                if (dist[i][j] > d1 + travel || (dist[i][j] == d1 + travel && path[i][j] > newPath)) {
                    s.erase({dist[i][j], i, j, path[i][j]});
                    dist[i][j] = d1 + travel;
                    path[i][j] = newPath;
                    s.insert({dist[i][j], i, j, newPath});
                }
            }
        }

        return "impossible";
    }
};
