// Problem link : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/ 

//Disjoint Set 


class Disjoint{
    
    vector<int>parent , size ; 

public : 
    Disjoint(int n){
        parent.resize(n+1) ; 
        size.resize(n+1) ; 
        for(int i =0 ; i<=n ; i++){
            parent[i]=i ; 
            size[i]=1 ; 
        }
    }
    
    
    int findPar(int node){
        if(node==parent[node]){
            return node ; 
        }
        
         return parent[node]=  findPar(parent[node]) ; 
    }
    
    void unionBySize(int u , int v){
        int ult_u = findPar(u) ; 
        int ult_v = findPar(v) ; 
        if(ult_u==ult_v){
            return  ; 
        }
        
        if(size[ult_u]<size[ult_v]){
            parent[ult_u] = ult_v ; 
            size[ult_v]++ ; 
        }
        
        else {
            parent[ult_v] = ult_u ; 
            size[ult_u]++ ;
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int , pair<int , int>>>edges ; 
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        Disjoint ds(V) ; 
        sort(edges.begin() , edges.end()) ; 
        int ans =0 ; 
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second; 
            
            if (ds.findPar(u) != ds.findPar(v)) {
                ans += wt;
                ds.unionBySize(u, v);
            }
        }
        
        return ans ; 
    }
};