// Given two strings ransomNote and magazine, return true if ransomNote can be 
// constructed by using the letters from magazine and false otherwise.
// Each letter in magazine can only be used once in ransomNote.

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m = ransomNote.length() ; 
        int n = magazine.length();
        unordered_map<char , int> mp ;  


        for(int i = 0 ; i<m ; i++){
            mp[ransomNote[i]]++ ; 

        }

        for(int i = 0 ; i<n ; i++){
            mp[magazine[i]]-- ; 
        }

        for(int i = 0 ; i<m ; i++){
            if(mp[ransomNote[i]]>0){
                return false ; 
            }
        }

        return true ; 
        
    }
};