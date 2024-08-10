// Problem Link : https://leetcode.com/problems/min-cost-to-connect-all-points/description/

 int prims(vector<vector<pair<int , int>>>&adj , int n){
        int sum = 0 ; 
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq ;
        vector<bool>vis(n , false) ; 

        pq.push({0 , 0}) ; 

        while(!pq.empty()){
            auto temp = pq.top() ; 
            int w = temp.first ; 
            int node = temp.second ; 
            pq.pop() ; 

            if(vis[node]){
                continue ; 
            }

            vis[node]=true ; 
            sum+=w ; 


            for(auto i : adj[node]){
                int w1 = i.second ; 
                int x = i.first ; 

                if(!vis[x]){
                    pq.push({w1 , x}); 
                }
            }
        }

        return sum ; 
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size() ; 
        vector<vector<pair<int , int>>>adj(n) ; 

        for(int i = 0 ; i<n ; i++){
            for(int j = i+1 ; j<n ; j++){
                int x1 = points[i][0] ; 
                int y1 = points[i][1] ; 

                int x2 = points[j][0] ; 
                int y2 = points[j][1] ; 

                int d = abs(x1-x2)+abs(y1-y2) ; 

                adj[i].push_back({j , d}); 
                adj[j].push_back({i , d}) ;
            }
        }

        return prims(adj , n) ; 
    }