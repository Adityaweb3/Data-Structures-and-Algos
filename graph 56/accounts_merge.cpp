// Problem link : https://leetcode.com/problems/accounts-merge/description/

class Disjoint {
    public : 
    vector<int>parent , size ; 

    Disjoint(int n){
        parent.resize(n+1) ; 
        size.resize(n+1) ; 

        for(int i =0 ; i<=n ; i++){
            parent[i]=i ; 
            size[i]=1 ; 
        }
    }

    int findPar(int node){
        if(node == parent[node]){
            return node ; 
        }

        return parent[node]= findPar(parent[node]) ; 
    }

    void unionBySize(int u ,int v){
        int ult_u = findPar(u) ; 
        int ult_v = findPar(v) ; 

        if(ult_u==ult_v){
            return ; 
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size() ; 
        Disjoint ds(n) ; 
        sort(accounts.begin() , accounts.end()) ; 
        unordered_map<string , int>mp ; 
        for(int i =0 ; i<n ; i++){
            for(int j =1 ; j<accounts[i].size(); j++){
                string res = accounts[i][j] ;
                if(mp.find(res)==mp.end()){
                    mp[res]=i ;
                } 
                else {
                    ds.unionBySize(i , mp[res]) ; 
                }
            }
        }

        vector<string>merged[n] ;
        for(auto it : mp){
            string res = it.first;
            int node = ds.findPar(it.second);
            merged[node].push_back(res);
        }

        vector<vector<string>>ans ; 
        for (int i = 0; i < n; i++) {
            if (merged[i].size() == 0) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : merged[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};