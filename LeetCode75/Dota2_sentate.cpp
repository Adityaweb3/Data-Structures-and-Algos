// Problem Link : https://leetcode.com/problems/dota2-senate/description/

 string predictPartyVictory(string senate) {
        queue<int>dq , rq ; 
        int n = senate.size() ; 
        for(int i = 0 ; i<n ; i++){
            if(senate[i]=='R'){
                rq.push(i) ;
            }

            else {
                dq.push(i) ;
            }
        }

        while(!dq.empty()&& !rq.empty()){
            int ri = rq.front() ; 
            rq.pop() ; 
            int di = dq.front() ; 
            dq.pop() ; 

            if(ri<di){
                rq.push(ri+n) ;
            }

            else {
                dq.push(di+n) ;
            }
        }

        if(!rq.empty()){
            return "Radiant" ;
        }

        else {
            return "Dire" ;
        }
    }