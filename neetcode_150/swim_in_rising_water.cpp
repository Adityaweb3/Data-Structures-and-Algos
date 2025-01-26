// Problem Link : https://leetcode.com/problems/swim-in-rising-water/

// Approach : if we want to go from (0 , 0) to (n-1 , n-1) in time t then all the values in the path will have value less
// than or equal to t ; 
// We can apply binary seach on answer here . 


 bool isvalid(int mid , vector<vector<int>>&grid , int n){
        queue<pair<int , int>>q ; 
        vector<vector<int>>vis(n , vector<int>(n)) ; 
        if(grid[0][0]<=mid){
            q.push({0 , 0}) ; 
            vis[0][0] =1 ; 
        }
        int dx[4] = {0 , -1 , 0 , 1} ; 
        int dy[4] = {-1 , 0 , 1 , 0} ; 
        while(!q.empty()){
            auto temp = q.front() ; 
            q.pop() ; 
            int row = temp.first ; 
            int col = temp.second ; 

            if(row==n-1 && col==n-1){
                return true ; 
            }

            for(int i = 0 ; i<4 ; i++){
                int newr = row+dx[i] ; 
                int newc = col+dy[i] ; 

                if(newr>=0 && newc>=0 && newr<n && newc<n && grid[newr][newc]<=mid && !vis[newr][newc]){
                    vis[newr][newc]=1 ; 
                    q.push({newr , newc}) ; 
                }
            }
        }

        return false ; 
    }
    int swimInWater(vector<vector<int>>& grid) {
       int n = grid.size() ; 
       int low = 0 ; 
       int high = n*n ; 
       int ans = 0 ; 
       while(low<=high){
        int mid = low+(high-low)/2 ; 
        if(isvalid(mid , grid , n)){
            ans = mid ; 
            high = mid-1 ; 
        }
        else {
            low = mid+1 ; 
        }
       }

       return ans ; 
    }