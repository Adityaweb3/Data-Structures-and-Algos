// Problem Link : https://neetcode.io/problems/top-k-elements-in-list


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int>mp ; 
         vector<int>res ;
        priority_queue<pair<int , int>>pq ; 

        for(auto i : nums){
            mp[i]++ ; 
        }

        for(auto i : mp){
            pq.push({i.second , i.first}) ;

        }
        while(k--){
            res.push_back(pq.top().second) ; 
            pq.pop() ; 
        }

        return res ; 
    }
};
