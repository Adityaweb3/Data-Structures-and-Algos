// Problem Link : https://leetcode.com/problems/design-underground-system/description/

class UndergroundSystem {
public:
unordered_map<int , pair<string , int>>check ; 
unordered_map<string  , pair<int , int>>path ; 
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        check[id]= {stationName , t} ; 
    }
    
    void checkOut(int id, string stationName, int t) {
        auto c = check[id] ; 
        check.erase(id) ; 

        string name = c.first +"_"+stationName ;
        path[name].first +=t-c.second ; 
        path[name].second +=1 ; 
    }
    
    double getAverageTime(string startStation, string endStation) {
        string res = startStation+"_"+endStation ; 
        auto ans = path[res] ; 

        return (double)ans.first/ans.second ; 
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */