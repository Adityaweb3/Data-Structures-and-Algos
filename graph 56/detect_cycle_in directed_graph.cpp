// Problem Link : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

 bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int indegree[V]= {0} ; 
        queue<int>q ;
        for(int i = 0 ; i<V ; i++){
            for(auto it : adj[i]){
                indegree[it]++ ;
            }
        }
        
        for(int i = 0 ; i<V ; i++){
            if(indegree[i]==0){
                q.push(i) ;
            }
        }
        
        int count = 0 ; 
        
        while(!q.empty()){
            int node = q.front() ; 
            q.pop() ; 
            count++ ; 
            
            for(auto i : adj[node]){
                indegree[i]-- ;
                
                if(indegree[i]==0){
                    q.push(i) ;
                }
            }
        }
        
        if(count==V){
            return false ;
        }
        
        return true ;
    }