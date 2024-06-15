// Problem Link : https://leetcode.com/problems/max-area-of-island/

int dfs(int i, int j, vector<vector<int>>& grid, int &ans) {
        grid[i][j] = 0; 
        int n = grid.size();
        int m = grid[0].size();
        int delrow[4] = {0, -1, 0, 1};
        int delcol[4] = {-1, 0, 1, 0};

        for (int k = 0; k < 4; k++) {
            int nr = i + delrow[k];
            int nc = j + delcol[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                ans++; 
                dfs(nr, nc, grid, ans); 
            }
        }

        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int ans = 1;  
                    res = max(res, dfs(i, j, grid, ans)); 
                }
            }
        }

        return res;
    }