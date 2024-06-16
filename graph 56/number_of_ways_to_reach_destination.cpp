// Problem Link : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

class Solution {
public:
    int mod = 1e9+7 ; 
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int , int>>adj[n] ; 
        for(auto it : roads){
            adj[it[0]].push_back({it[1] , it[2]}) ; 
            adj[it[1]].push_back({it[0] , it[2]}) ; 
        }

        priority_queue<pair<long long , int> , vector<pair<long long, int>> , greater<pair<long long , int>>>pq ; 
        vector<long long>dist(n , 1e18) ; 
        vector<int>ans(n , 0) ; 
        dist[0]=0 ; 
        ans[0]=1 ; 
        pq.push({0 , 0}) ; 

        while(!pq.empty()){
            long long dis = pq.top().first ; 
            int node = pq.top().second ; 
            pq.pop() ; 

            for(auto it : adj[node]){
                int adjNode = it.first ; 
                long long edN = it.second ; 

                if(dis+edN<dist[adjNode]){
                    dist[adjNode]=dis+edN ; 
                    pq.push({dist[adjNode] , adjNode}) ; 
                    ans[adjNode]=ans[node] ; 
                }
                else if(dis+edN==dist[adjNode]){
                    ans[adjNode]= (ans[adjNode]+ans[node])%mod ; 
                }
            }
        }

        return ans[n-1]%mod ; 
    }
};