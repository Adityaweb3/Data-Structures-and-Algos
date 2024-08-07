// Problem link : https://neetcode.io/problems/islands-and-treasure

void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        int m = grid[0].size() ; 
        vector<vector<int>>vis(n , vector<int>(m , 0)) ; 
        queue<pair<pair<int , int> , int>>q ; 
        int delrow[4]= {0 , -1 , 0 ,1} ; 
        int delcol[4]= {-1 , 0 , 1 , 0} ; 
        
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j]==0){
                    vis[i][j]=1 ; 
                    q.push({{i , j} , 0}) ; 
                }
            }
        }

        while(!q.empty()){
            auto temp = q.front() ;
            q.pop() ;  
            int r = temp.first.first ; 
            int c = temp.first.second ; 
            int d = temp.second ; 

            for(int i =0 ; i<4 ; i++){
                int newr = r+delrow[i] ; 
                int newc = c+delcol[i] ; 

                if(newr<n && newr>=0 && newc<m && newc>=0 && !vis[newr][newc] && grid[newr][newc]==2147483647){
                    vis[newr][newc]=1 ; 
                    q.push({{newr , newc} , d+1}) ; 
                    grid[newr][newc]=d+1 ; 
                }
            }

        }

    }