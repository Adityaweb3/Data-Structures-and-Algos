// Problem Link : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int>vis(V , 0) ;
        int sum =0 ;
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq ; 
        pq.push({0 , 0}) ; 
        
        while(!pq.empty()){
            auto it = pq.top() ; 
            pq.pop() ; 
            int node = it.second ; 
            int wt = it.first ; 
            
            if(vis[node]==1){
                continue ;
            }
            vis[node]=1 ;
            sum+=wt ;
            
            for(auto i : adj[node]){
                int adjNode = i[0] ; 
                int adjwt = i[1] ; 
                
                if(!vis[adjNode]){
                    pq.push({adjwt , adjNode}) ;
                }
            }
        }
        
        
        return sum ;
    }