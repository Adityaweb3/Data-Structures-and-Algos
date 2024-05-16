// Problem Link : https://leetcode.com/problems/domino-and-tromino-tiling/description/

 int numTilings(int n) {
        int md = 1e9 ; 
        md+=7 ; 
        vector<long long>res(1001 , 0) ;
        res[1]=1 ; 
        res[2]=2 ; 
        res[3]=5 ; 
        if(n<=3){
            return res[n] ; 
        }

        for(int i=4 ; i<=n ; i++){
            res[i]= 2*res[i-1]+res[i-3] ; 
            res[i]%=md ; 
        }

        return res[n] ;
    }