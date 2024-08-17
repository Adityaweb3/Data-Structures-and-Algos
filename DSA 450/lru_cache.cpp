// Problem Link : https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    list<int>dll ; 
    map<int , pair<list<int>::iterator , int>>mp ; 
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity ; 
    }

    void makeRecent(int key){
        dll.erase(mp[key].first) ; 
        dll.push_front(key) ;
        mp[key].first = dll.begin() ; 
    }
    
    int get(int key) {
        if(!mp.count(key)){
            return -1 ; 
        }
        makeRecent(key) ; 
        return mp[key].second ; 
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key].second = value ; 
            makeRecent(key) ; 
        }
        else {
            dll.push_front(key) ; 
            mp[key]={dll.begin() , value} ; 
            capacity-- ; 
        }
        if(capacity<0){
            mp.erase(dll.back()) ; 
            dll.pop_back() ; 
            capacity++ ; 
        }

    }
};