// Problem Link : https://leetcode.com/problems/custom-sort-string/

string customSortString(string order, string s) {
        unordered_map<char ,int>mp ; 
        string ans= "" ; 

        for(auto i : s){
            mp[i]++ ; 
        }

        for(auto i : order){
            if(mp[i]>0){
                while(mp[i]>0){
                    ans+=i ; 
                    mp[i]-- ; 
                }
            }
        }

        for(auto i : mp){
            if(i.second>0){
                while(i.second>0){
                    ans+=i.first ;
                    i.second-- ;  
                }
            }
        }

        return ans ; 
    }