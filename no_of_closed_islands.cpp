// Problem Link : https://leetcode.com/problems/number-of-closed-islands/description/

void dfs(int i , int j , int n , int m ,vector<vector<int>>& grid ){
        grid[i][j]=1 ; 
        int delrow[4]= {0 , -1 , 0 , 1} ; 
        int delcol[4]= {-1 , 0 , 1 , 0} ; 

        for(int k =0 ; k<4 ; k++){
            int newr= i+delrow[k] ; 
            int newc = j+delcol[k] ; 

            if(newr<n && newr>=0 && newc>=0 && newc<m && grid[newr][newc]==0){
                dfs(newr , newc , n , m , grid) ; 
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        int m = grid[0].size() ; 
        int count = 0 ; 

        for(int i =0; i<n ; i++){
            for(int j =0 ; j<m ; j++){
                if(i*j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==0){
                        dfs(i , j, n , m, grid) ; 
                    }
                }
            }
        }

        for(int i =0 ; i<n ; i++){
            for(int j =0 ; j<m ; j++){
                if(grid[i][j]==0){
                    count++ ; 
                    dfs(i , j , n , m , grid) ; 
                }
            }
        }

        return count; 
    }