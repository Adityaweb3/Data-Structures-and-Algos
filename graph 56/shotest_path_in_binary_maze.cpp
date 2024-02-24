// Problem Link : https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1


if (source.first == destination.first &&
            source.second == destination.second){
                return 0;
            }
             
        int n = grid.size() ; 
        int m = grid[0].size() ; 
        queue<pair<int , pair<int , int>>>q ;
        vector<vector<int>>dist( n , vector<int>(m , 1e9)) ;
        dist[source.first][source.second]=0 ; 
        int dr[]= {-1 , 0 , 1 , 0} ; 
        int dc[]= {0 , 1 , 0 , -1} ;
        q.push({0 , {source.first , source.second}}) ;
        
        while(!q.empty()){
            auto it = q.front() ; 
            
            int dis = it.first ; 
            int r = it.second.first ; 
            int c = it.second.second ; 
            q.pop() ;
            for(int i = 0 ; i<4 ; i++){
                int newr = r + dr[i] ; 
                int newc = c + dc[i] ; 
                
                if(newr<n && newr>=0 && newc<m && newc>=0 && grid[newr][newc]==1 && dis +1 <dist[newr][newc]){
                    dist[newr][newc]= dis+1 ; 
                    if(newr== destination.first && newc==destination.second){
                        return dis+1 ; 
                    }
                    
                    q.push({dis+1 , {newr , newc}}) ;
                }
            }
        }
        
        return -1 ;
