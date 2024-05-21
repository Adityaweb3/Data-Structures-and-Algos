// Problem Link : https://leetcode.com/problems/detonate-the-maximum-bombs/description/

class Solution {
public:
  typedef long long ll ;

  void dfs(vector<vector<int>>&adj , vector<bool> &visited,int &c,int &i){
    visited[i]=true ; 
    c++ ; 
    for(int j = 0 ; j<adj[i].size() ; j++){
        if(!visited[adj[i][j]]){
            dfs(adj , visited , c , adj[i][j]) ; 
        }
    }
  }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size() ; 
        vector<vector<int>>adj(n) ;

        for(int i = 0 ; i<n ; i++){
            ll x1 , y1 , r1 ; 
            x1 = bombs[i][0] ; 
            y1= bombs[i][1] ; 
            r1 = bombs[i][2] ; 
            for(int j =0 ; j<n ; j++){
                if(i!=j){
                    ll x2 , y2 , r2 ; 
                    x2 = abs(x1-bombs[j][0]) ; 
                    y2 = abs(y1-bombs[j][1]) ; 
                    if(x2*x2 + y2*y2 <=r1*r1){
                        adj[i].push_back(j) ; 
                    }
                }
            }

        }

        int ans = INT_MIN ; 
            for(int i = 0 ; i<n ; i++){
                int c = 0 ; 
                vector<bool>visited(n , false) ; 
                dfs(adj , visited , c,i) ; 
                ans = max(ans , c) ;
            }

        return ans ; 
    }
};