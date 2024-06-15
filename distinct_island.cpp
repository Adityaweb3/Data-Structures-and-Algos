// Problem link : https://www.geeksforgeeks.org/problems/number-of-distinct-islands/

class Solution {
  public:
  
  void dfs(int i , int j , vector<vector<int>>&vis ,vector<vector<int>>& grid,int baseX , int baseY , vector<pair<int , int>>&temp){
      int n = grid.size() ; 
      int m = grid[0].size() ; 
      int a = i-baseX ; 
      int b = j -baseY ; 
      temp.push_back({a,b}) ; 
      vis[i][j]=1 ; 
      
      int delrow[4]= {0 , -1 , 0 , 1} ; 
      int delcol[4]= {-1 , 0 , 1 , 0} ; 
      
      for(int u=0 ; u<4 ; u++){
          int newr = i +delrow[u] ; 
          int newc = j+delcol[u] ; 
          
          if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && grid[newr][newc]){
              dfs(newr , newc , vis , grid , baseX , baseY , temp) ; 
          }
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size() ; 
        int m = grid[0].size() ; 
        set<vector<pair<int , int>>>st ; 
        vector<vector<int>>vis(n , vector<int>(m , 0)) ; 
        for(int i = 0 ; i<n ; i++){
            for(int j =0 ; j<m ; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int , int>>temp ; 
                    dfs(i,j,vis,grid,i,j,temp) ; 
                    st.insert(temp) ; 
                }
            }
        }
        
        return st.size() ; 
    }
};