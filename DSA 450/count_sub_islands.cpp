// Problem Link : https://leetcode.com/problems/count-sub-islands/

bool dfs(int i , int j , vector<vector<int>>&grid1 , vector<vector<int>>&grid2 , vector<vector<int>>&vis){
    vis[i][j] =1 ; 
    int delrow[4] = {0 , -1 , 0 , 1} ; 
    int delcol[4] = {-1 , 0 , 1 , 0} ; 
    int n = grid2.size() ; 
    int m = grid2[0].size() ; 
    bool flag = true; 
    if(!grid1[i][j]){
        flag = false ; 
    }
    for(int k= 0 ; k<4 ; k++){
        int newr = i+delrow[k] ; 
        int newc = j+delcol[k] ; 
        if(newr<n && newr>=0 && newc<m && newc>=0 && !vis[newr][newc] && grid2[newr][newc]){
            if(!dfs(newr , newc , grid1 , grid2 , vis)){
                flag = false ; 
            }
        }
    }
    return flag ; 

}
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int ans =0 ; 
    int n = grid2.size() ; 
    int m = grid2[0].size() ; 
    vector<vector<int>>vis(n , vector<int>(m , 0)) ; 
    for(int i = 0 ; i<n ; i++){
        for(int j = 0; j<m ; j++){
            if(grid2[i][j] && !vis[i][j] && dfs(i , j , grid1 , grid2 , vis)){
                ans++ ; 
            }
        }
    }
    return ans ; 
}