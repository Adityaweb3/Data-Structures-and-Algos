/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters 
and removing all non-alphanumeric characters, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.*/

#include <bits/stdc++.h> 
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