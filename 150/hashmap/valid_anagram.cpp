// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length() ;
        int m = t.length() ; 

        if(m >n || m<n){
            return false ; 
        }
        unordered_map<char, int>mp ; 

        for(int i = 0 ; i< n ; i++){
            mp[s[i]]++ ; 

        }

        for(int i = 0 ; i<m ; i++){
            mp[t[i]]-- ; 
        }

        for(int i = 0 ; i<n ; i++){
            if(mp[s[i]]>0){
                return false ;
            }
        }

        return true ;
        
    }
};