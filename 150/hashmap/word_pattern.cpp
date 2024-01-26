// Given a pattern and a string s, find if s follows the same pattern.
// Here follow means a full match, such that there is a bijection between 
// a letter in pattern and a non-empty word in s.

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>v ; 
        int i = 0;
        string temp = "" ;
        while(i<s.size()){

            if(s[i]==' '){
                v.push_back(temp) ; 
                temp = "" ;
            }

            else {
                temp+=s[i] ;
            }

            i++ ;

        }
        v.push_back(temp) ;

        if(v.size()!= pattern.length()){
            return false ;
        }

        unordered_map<char, string>mp ;
        unordered_set<string>taken;

        for(int i = 0 ; i<pattern.length(); i++){
            if(mp.find(pattern[i]) == mp.end() && taken.find(v[i]) == taken.end()){
                mp[pattern[i]] = v[i] ; 
                taken.insert(v[i]) ;
            }

            else {
                if(mp[pattern[i]] != v[i]){
                    return false ;
                }
            }
        }

        return true ;

        
        
    }
};