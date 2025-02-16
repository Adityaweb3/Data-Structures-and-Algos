// Problem link : https://leetcode.com/problems/longest-path-with-different-adjacent-characters/

 int solve(int curr , string &s , int &ans , vector<int>adj[]){
        int maxi = 0 ; 
        int maxi1= 0 ; 
        for(auto i : adj[curr]){
            int len = solve(i , s , ans , adj) ; 
            if(s[i]==s[curr]){
                continue ; 
            }
            if(len>maxi){
                maxi1 = maxi ; 
                maxi = len ; 
            }
            else if(len>maxi1){
                maxi1 = len ; 
            }
        }
        int res1 = 1+maxi ; 
        int res2 = 1+maxi+maxi1 ; 
        ans = max({ans , res1 , res2}) ; 
        return res1 ; 
    }
    int longestPath(vector<int>& parent, string s) {
        vector<int>adj[100005] ; 
        int ans = 0 ; 
        for(int i =1 ; i<parent.size() ; i++){
            adj[parent[i]].push_back(i) ; 
        }
        solve(0 , s , ans , adj) ; 
        return ans ; 
    }