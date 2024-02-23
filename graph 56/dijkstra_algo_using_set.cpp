 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
       set<pair<int , int>>st ; 
       vector<int>dist(V , 1e9) ; 
       
       dist[S]= 0 ; 
       st.insert({0 , S}) ; 
       
       while(!st.empty()){
           auto it = *(st.begin()) ;
           int dis = it.first ; 
           int node = it.second ; 
           st.erase(it) ; 
           
           for(auto i : adj[node]){
               int adjNode = i[0] ; 
               int adjW = i[1] ; 
               
               if(dis + adjW <dist[adjNode]){
                  if(dist[adjNode] != 1e9) 
                        st.erase({dist[adjNode], adjNode}); 
                        
                    
                    dist[adjNode] = dis + adjW; 
                    st.insert({dist[adjNode], adjNode});  
                   
               }
           }
       }
       
       return dist ;
    }