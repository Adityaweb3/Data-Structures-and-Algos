// Problem link : https://leetcode.com/problems/redundant-connection/description/

class Disjoint {
    public : 
    vector<int>parent , size ; 

    Disjoint(int n){
        parent.resize(n+1) ; 
        size.resize(n+1) ; 
        for(int i =0 ; i<=n ; i++){
            parent[i]=i ; 
            size[i]=i ; 
        }
    }

    int findPar(int node){
        if(node==parent[node]){
            return node ; 
        }

        return parent[node]= findPar(parent[node]) ; 
    }

    void unionBySize(int u , int v){
        int ult_u = findPar(u) ; 
        int ult_v = findPar(v) ; 
        if(ult_u==ult_v){
            return  ;
        }

        if(size[ult_u]>size[ult_v]){
            parent[ult_v]= ult_u ; 
            size[ult_u]+=size[ult_v] ; 
        }
        else {
            parent[ult_u]= ult_v ; 
            size[ult_v]+=size[ult_u] ; 
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() ; 
        Disjoint ds(n) ;
        vector<int>ans ; 

        for(auto i : edges){
            int u = i[0] ; 
            int v = i[1] ; 
            
            if(ds.findPar(u)==ds.findPar(v)){
                ans.push_back(u) ; 
                ans.push_back(v) ; 
                return ans ; 
            }

            ds.unionBySize(u , v) ; 
        }

        return ans ; 
    }
};