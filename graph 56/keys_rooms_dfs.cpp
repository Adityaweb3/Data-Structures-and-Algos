// Problem Link : https://leetcode.com/problems/keys-and-rooms/

 void dfs(int room , vector<vector<int>>&rooms , vector<bool>&vis){
       if(vis[room]){
           return ;
       }
       vis[room]=1 ; 

       for(int key : rooms[room]){
           if(key==room){
               continue ;
           }

           if(vis[key]){
               continue ;
           }

           dfs(key , rooms , vis) ;
       }
   }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>vis(rooms.size()+1 , 0) ; 
        dfs(0 , rooms , vis) ; 
        for(int i = 0 ; i<rooms.size(); i++){
            if(!vis[i]){
                return 0 ;
            }
        }

        return 1 ;
    }