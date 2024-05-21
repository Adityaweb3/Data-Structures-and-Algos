// Problem Link : https://neetcode.io/problems/is-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0 ; 
        int high = s.size()-1 ; 
        while(start<=high){
            if(!isalnum(s[start])){
                start++ ;
                continue ; 
            }

            if(!isalnum(s[high])){
                high-- ; 
                continue ; 
            }

            if(tolower(s[start])!=tolower(s[high])){
                return false ; 
            }

            else {
                start++ ; 
                high-- ;
            }
        }

        return true ;
    }
};
