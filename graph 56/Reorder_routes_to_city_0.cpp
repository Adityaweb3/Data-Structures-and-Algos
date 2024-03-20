// Problem Link : https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description

 int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool>vis(n ,0) ; 
        queue<int>q ; 
        vector<pair<int , bool>>adj[n] ; 

        for(auto x : connections){
            adj[x[0]].push_back({x[1] , true}) ;
            adj[x[1]].push_back({x[0] , false}) ;
        }
        q.push(0) ; 
        int res =0 ; 

        while(!q.empty()){
            int curr = q.front() ; 
            q.pop() ; 
            vis[curr]=1 ; 
            for(auto x :adj[curr]){
                if(vis[x.first]){
                    continue ;
                }
                q.push(x.first) ;
                if(x.second){
                    res++ ;
                }
            }
        }

        return res ;
    }