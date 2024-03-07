// Problem Link : https://leetcode.com/problems/ipo/description/

 int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size() ; 
        vector<pair<int , int>>res ; 
        for(int i = 0 ; i<n ; i++){
            res.push_back({capital[i] , profits[i]}) ;
        }

        sort(res.begin() , res.end()) ;
        priority_queue<int>pq ; 
        int i = 0 ;

        while(k){
            while(i<n && res[i].first<=w){
                pq.push(res[i++].second) ; 
            }

            if(pq.empty()){
                break ; 
            }

            w+=pq.top() ; 
            pq.pop() ; 
            k-- ; 
        }

        return w ; 
    }