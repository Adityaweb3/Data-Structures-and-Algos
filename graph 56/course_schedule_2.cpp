// Problem link : https://leetcode.com/problems/course-schedule-ii/



vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
         vector<int>adj[V] ; 
        
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]) ;
        }
        
        vector<int>indegree(V , 0) ; 
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
	    
	    if(ans.size()==V){
	        return ans ;
	    }
	    else {
	        return {}; 
	    }
    }