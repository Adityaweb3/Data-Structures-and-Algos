	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int indegree[V]={0} ; 
	    queue<int>q ;
	    for(int i = 0 ; i<V ; i++){
	        
	        for(auto it : adj[i]){
	            indegree[it]++ ;
	        }
	        
	    }
	    
	    for(int i = 0 ; i<V; i++){
	        if(indegree[i]==0){
	            q.push(i) ;
	        }
	    }
	    vector<int>ans ; 
	    
	    while(!q.empty()){
	        int node = q.front() ; 
	        q.pop() ; 
	        ans.push_back(node) ; 
	        
	        for(auto i : adj[node]){
	            indegree[i]-- ; 
	            
	            if(indegree[i]==0){
	                q.push(i) ;
	            }
	        }
	    }
	    
	    return ans ;
	    
	    
	}