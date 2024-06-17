// Problem link : https://www.geeksforgeeks.org/problems/number-of-provinces/

class disjointset{

    
    public:
    vector<int> parent, size;
    
    disjointset(int n){
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0; i<=n ; i++){
            parent[i]=i ; 
            size[i]=1 ; 
        }
    }

   int findupar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findupar(parent[node]);
    }
    
    void unionBySize( int u, int v){
    int ulp_u = findupar(u);
    int ulp_v = findupar(v);

    if(ulp_v == ulp_u) return;

    if(size[ulp_u] < size[ulp_v]){
        parent[ulp_u] = ulp_v;
        size[ulp_v]++ ; 
    }
    
    
    else{
        parent[ulp_v] = ulp_u;
        size[ulp_u]++;
    }

}


};
class Solution {
    
    
    public:




    int numProvinces(vector<vector<int>> adj, int n){
        disjointset ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] == 1) {
                    ds.unionBySize(i, j);
                }
            }
        }
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(ds.parent[i] == i) cnt++;
    }
    return cnt;
}
};