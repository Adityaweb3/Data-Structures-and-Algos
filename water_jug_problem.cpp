// Problem Link : https://leetcode.com/problems/water-and-jug-problem/

bool dfs(int n , int x , int y , int index , int target , vector<int>&vis){
        if(index>n || index<0 || vis[index]==1){
            return false ; 
        }
        vis[index]=1; 
        if(index==target){
            return true ; 
        }
        bool a =  dfs(n , x , y , index+x , target , vis) ; 
        bool b = dfs(n , x , y , index-x , target , vis) ; 
        bool c = dfs(n , x , y , index+y , target , vis) ; 
        bool d = dfs(n , x , y , index-y , target , vis) ; 
        return a | b | c | d ; 
    }
    bool canMeasureWater(int x, int y, int target) {
        int n = x+y ; 
        vector<int>vis(n+1 , 0) ; 
        return dfs(n , x , y , 0 , target , vis) ; 
    }