// Problem Link : https://leetcode.com/problems/reorganize-string/description/

 string reorganizeString(string s) {
        unordered_map<char , int>mp ; 
        for(auto ch : s){
            mp[ch]++ ; 
        }

        priority_queue<pair<int , char> , vector<pair<int, char>>> pq;

        for(auto it : mp){
            pq.push({it.second , it.first}) ;
        }
        int size = s.size() ; 
        int index = 0 ; 

        while(!pq.empty()){
            auto top = pq.top() ; 
            pq.pop() ; 
            int freq = top.first ; 
            char text = top.second ; 

            if(2*freq-1 >size){
                return "" ;
            }

            while(freq-- >0){
                if(index>=size){
                    index = 1 ;
                }

                s[index]= text ; 
                index+=2 ;
            }
        }

        return s ;
    }