// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
// You may assume all four edges of the grid are all surrounded by water.

class Solution {
private :
   void bfs(int row , int col , vector<vector<int>>&vis ,vector<vector<char>>& grid ){
      vis[row][col]=1 ;
      queue<pair<int,int>>q ;
      int n = grid.size() ;
      int m = grid[0].size() ;
      vector<int>rI={-1,0,1,0};
      vector<int>cI={0,1,0,-1};
      
      q.push({row,col}) ;
      
      while(!q.empty()){
          int row = q.front().first ;
          int col = q.front().second ;
          q.pop() ;
          
          for(int dir= 0 ; dir<4 ; dir++){
            // movement is allowed in only hhorizontaly or vertically 
                  int nrow= row+rI[dir] ;
                  int ncol = col+cI[dir] ;
                  
                  if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] =='1' && !vis[nrow][ncol]){
                      vis[nrow][ncol]=1 ;
                      q.push({nrow,ncol}) ;
                      
                  }
                  
              }
          }
      
  }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        int count =0 ;
        
        
        vector<vector<int>>vis(n , vector<int>(m , 0)) ;
        
        for(int row = 0 ; row<n ; row++){
            for(int col = 0 ; col<m ; col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    count++ ;
                    bfs(row,col, vis , grid) ;
                }
            }
        }
        
        return count ;
        
    }
};