// Problem Link : https://leetcode.com/problems/string-compression-iii/description/

class Solution {
public:
    string compressedString(string word) {
        string ans ="" ; 
        int res =0 ; 
        int i =0 ; 
        int j = 0 ; 

        while(j<word.size()){
            res = 0 ; 

            while(j<word.size() && word[i]==word[j] && res <9){
                j++ ; 
                res++ ; 
            }

            ans+=to_string(res)+word[i] ; 
            i=j ; 
        }

        return ans ; 
    }
};