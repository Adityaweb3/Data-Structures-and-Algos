// Problem link : https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class DisjointSet {
public : 
   vector<int>parent , size ; 

   DisjointSet(int n){
    parent.resize(n+1) ; 
    size.resize(n+1) ; 

    for(int i =0 ; i<=n ; i++){
        parent[i]=i ; 
        size[i]=1 ; 
    }
   }

   int findPar(int node){
    if(node ==parent[node]){
        return node ; 
    }

    return parent[node]=findPar(parent[node]) ; 
   }

   void unionBySize(int u , int v){
    int ult_u = findPar(u) ; 
    int ult_v = findPar(v) ; 

    if(ult_u==ult_v){
        return ; 
    }

    if(size[ult_u]>size[ult_v]){
        parent[ult_v]= ult_u ; 
        size[ult_u]+= size[ult_v] ; 
    }
    else {
        parent[ult_u]= ult_v ; 
        size[ult_v]+=size[ult_u] ; 
    }
   }
        
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n) ; 
        int count =0 ; 

        for(auto i : connections){
            int u = i[0] ; 
            int v = i[1] ; 

            if(ds.findPar(u)==ds.findPar(v)){
                count++ ; 
            }

            ds.unionBySize(u , v) ; 
        }

        int cnt =0 ; 
        for(int i =0 ; i<n ; i++){
           if(ds.parent[i]==i){
            cnt++ ; 
           }
        }

        int ans = cnt-1 ; 

        if(ans<=count){
            return ans ; 
        }
        else {
            return -1 ; 
        }
    }
};