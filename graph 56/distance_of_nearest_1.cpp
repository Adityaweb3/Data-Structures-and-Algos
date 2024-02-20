// Problem Link : https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

//BFS ;

	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size() ; 
	    int m = grid[0].size() ; 
	    vector<vector<int>>distance(n , vector<int>(m , 0)) ;
	    vector<vector<int>>vis(n, vector<int>(m,0)) ; 
	    queue<pair<pair<int , int> , int>>q ;
	    
	    for(int i = 0 ; i<n ; i++){
	        for(int j = 0 ; j<m ; j++){
	            if(grid[i][j]==1){
	                vis[i][j]=  1; 
	                q.push({{i,j} , 0}) ;
	            }
	            
	            else {
	                vis[i][j]=0 ;
	            }
	        }
	    }
	    
	    int delRow[]= {-1 , 0 ,1 ,0} ; 
	    int delCol[]= {0 , 1 , 0 , -1} ; 
	    
	   while(!q.empty()){
	       int r = q.front().first.first ;
	       int c= q.front().first.second ; 
	       int steps= q.front().second ; 
	       q.pop() ;
	       distance[r][c]= steps ;
	       
	       for(int i = 0 ; i<4 ; i++){
	           int nrow = r+ delRow[i] ; 
	           int ncol = c + delCol[i] ; 
	           
	           if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && vis[nrow][ncol]==0){
	               vis[nrow][ncol]=1 ; 
	               q.push({{nrow , ncol} , steps+1})  ;
	           }
	       }
	   }
	   
	   return distance ;
	}