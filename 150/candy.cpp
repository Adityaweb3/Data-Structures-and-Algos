// Problem link : https://leetcode.com/problems/candy/description/

int candy(vector<int>& ratings) {
        int ans = 0 ; 
        int n = ratings.size() ;

        vector<int>res(n , 1) ; 

        if(n==1){
            return 1 ; 
        }

        for(int i =1 ; i<n ; i++){
            if(ratings[i]>ratings[i-1] && res[i]<=res[i-1]){
                res[i]= res[i-1]+1 ; 
            }
        }

        for(int i = n-2 ; i>=0 ; i--){
            if(ratings[i]>ratings[i+1] && res[i]<=res[i+1]){
                res[i]=res[i+1]+1 ; 
            }
        }

        for(auto i : res){
            ans+=i ; 
        }

        return ans ; 
    }