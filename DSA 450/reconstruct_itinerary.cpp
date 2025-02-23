// Problem Link : https://leetcode.com/problems/reconstruct-itinerary/description/

void solve(string u , vector<string>&ans , unordered_map<string , priority_queue<string , vector<string> , greater<string>>>&mp){
    auto &res = mp[u] ; 
    while(!res.empty()){
        auto temp = res.top() ; 
        res.pop() ; 
        solve(temp , ans , mp) ; 
    }
    ans.push_back(u) ; 
   }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string>ans ; 
        unordered_map<string , priority_queue<string , vector<string> , greater<string>>>mp ; 
        for(auto i : tickets){
            mp[i[0]].push(i[1]) ; 
        }
        solve("JFK" , ans , mp) ; 
        reverse(ans.begin() , ans.end()) ; 
        return ans ; 
    }