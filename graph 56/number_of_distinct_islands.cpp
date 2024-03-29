// Problem Link : https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

 void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int baseX, int baseY, vector<pair<int,int>>& temp) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vis[row][col] = 1 ;
        int a = row-baseX ;
        int b = col-baseY ;
        temp.push_back({a, b}) ;
        
        int dx[] = {-1, 0, 1, 0 } ;
        int dy[] = {0, 1, 0, -1 } ;
        
        for(int i=0; i<4; i++) {
            int x = row+dx[i] ;
            int y = col+dy[i] ;
            
            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y]) {
                dfs(x,y,vis,grid,baseX,baseY,temp) ;
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
         int n = grid.size() ;
        int m = grid[0].size() ;
        set<vector<pair<int,int>>> st ;
        vector<vector<int>> vis(n, vector<int>(m, 0)) ;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]) {
                    vector<pair<int,int>> temp ;
                    dfs(i,j,vis,grid,i,j,temp) ;
                    st.insert(temp) ;
                }
            }
        }
        
        return st.size() ;
        
    } 