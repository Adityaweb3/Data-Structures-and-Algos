// Problem Link : https://leetcode.com/problems/fruit-into-baskets/description/

int totalFruit(vector<int>& arr) {
        int n = arr.size() ; 
        int l = 0 ; 
        int r =0 ; 
        int maxlen=0 ; 
        unordered_map<int , int>mp ;

        while(r<n){
            mp[arr[r]]++ ; 

            if(mp.size()>2){
                mp[arr[l]]-- ; 
                if(mp[arr[l]]==0){
                    mp.erase(arr[l]) ; 
                }
                l++ ; 
            }

            if(mp.size()<=2){
                maxlen = max(maxlen , r-l+1) ; 
            }
            r++ ; 
        }

        return maxlen ; 
    }