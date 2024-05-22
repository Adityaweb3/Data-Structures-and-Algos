// Problem Link : https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
       int n = maze.size();
       int m = maze[0].size();

       queue<pair<int, int>> q;
      q.push({entrance[0], entrance[1]});
       maze[entrance[0]][entrance[1]] = '+';
       int steps = 0;

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    while (!q.empty()) {
        int N = q.size();
        while (N--) {
            auto temp = q.front();
            q.pop();
            int r = temp.first;
            int c = temp.second;

            
            if ((r != entrance[0] || c != entrance[1]) && (r == 0 || r == n - 1 || c == 0 || c == m - 1)) {
                return steps;
            }

            for (int i = 0; i < 4; i++) {
                int newR = r + delrow[i];
                int newC = c + delcol[i];

                if (newR < n && newR >= 0 && newC < m && newC >= 0 && maze[newR][newC] != '+') {
                    q.push({newR, newC});
                    maze[newR][newC] = '+';
                }
            }
        }
        steps++;
    }

    return -1;
    }
};