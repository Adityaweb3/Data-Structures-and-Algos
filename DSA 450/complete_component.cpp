// Problem link : https://leetcode.com/problems/count-the-number-of-complete-components/description/

class Solution {
    public:
       vector<int>par , count , sz ; 
       int findPar(int u){
        if(par[u]==-1){
            return u ; 
        }
        return findPar(par[u]) ; 
       }
        void unionSz(int u , int v){
            int par_u= findPar(u) ;
            int par_v = findPar(v) ; 
            count[par_u]++ ; 
            if(par_u!=par_v){
                par[par_v]=par_u ; 
                count[par_u]+=count[par_v] ; 
                sz[par_u]+=sz[par_v]; 
            }
        }
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            int ans = 0 ; 
            par.assign(n , -1) ; 
            count.assign(n, 0) ; 
            sz.assign(n , 1) ; 
            for(auto i : edges){
                unionSz(i[0] , i[1]) ; 
            }
            for(int i = 0 ; i<n ; i++){
                if(par[i]==-1){
                    int c= sz[i] ; 
                    int res = c*(c-1)/2 ; 
                    if(res==count[i]){
                        ans++ ; 
                    }
                }
            }
            return ans ; 
        }
    };