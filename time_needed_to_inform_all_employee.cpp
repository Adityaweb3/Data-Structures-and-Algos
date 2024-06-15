// Problem Link : https://leetcode.com/problems/time-needed-to-inform-all-employees/

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n) ; 
        for(int i =0 ; i<n ; i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i) ; 
            }
        }

        queue<pair<int, int>>q ; 
        int count =0 ; 
        q.push({headID , 0}) ; 

        while(!q.empty()){
            auto u = q.front() ; 
            q.pop() ; 
            int index = u.first ; 
            int cnt = u.second ; 
            count = max(count , cnt) ; 

            for(auto it : adj[index]){
                q.push({it , cnt+informTime[index]}) ; 
            }
        }

        return count ; 
    }