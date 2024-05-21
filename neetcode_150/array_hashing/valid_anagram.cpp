// Problem Link : https://leetcode.com/problems/valid-anagram/description/

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