// Problem Link : https://leetcode.com/problems/pacific-atlantic-water-flow/description/

void bfs2(vector<vector<int>>& heights, vector<vector<int>>& vis2) {
    int n = heights.size();
    int m = heights[0].size();
    int delRow[4] = {0, -1, 0, 1};
    int delCol[4] = {-1, 0, 1, 0};
    queue<pair<int, int>> q;
    
    for (int i = 0; i < n; ++i) {
        vis2[i][m - 1] = 1;
        q.push({i, m - 1});
    }
    for (int j = 0; j < m; ++j) {
        vis2[n - 1][j] = 1;
        q.push({n - 1, j});
    }

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        int r = temp.first;
        int c = temp.second;

        for (int i = 0; i < 4; ++i) {
            int newR = r + delRow[i];
            int newC = c + delCol[i];

            if (newR < n && newR >= 0 && newC < m && newC >= 0 && !vis2[newR][newC] && heights[newR][newC] >= heights[r][c]) {
                vis2[newR][newC] = 1;
                q.push({newR, newC});
            }
        }
    }
}

void bfs1(vector<vector<int>>& heights, vector<vector<int>>& vis1) {
    int n = heights.size();
    int m = heights[0].size();
    int delRow[4] = {0, -1, 0, 1};
    int delCol[4] = {-1, 0, 1, 0};
    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i) {
        vis1[i][0] = 1;
        q.push({i, 0});
    }
    for (int j = 0; j < m; ++j) {
        vis1[0][j] = 1;
        q.push({0, j});
    }

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        int r = temp.first;
        int c = temp.second;

        for (int i = 0; i < 4; ++i) {
            int newR = r + delRow[i];
            int newC = c + delCol[i];

            if (newR < n && newR >= 0 && newC < m && newC >= 0 && !vis1[newR][newC] && heights[newR][newC] >= heights[r][c]) {
                vis1[newR][newC] = 1;
                q.push({newR, newC});
            }
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> vis1(n, vector<int>(m, 0));
    vector<vector<int>> vis2(n, vector<int>(m, 0));
    vector<vector<int>> ans;

    bfs1(heights, vis1);
    bfs2(heights, vis2);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vis1[i][j] && vis2[i][j]) {
                ans.push_back({i, j});
            }
        }
    }

    return ans;

        
    }