// You have been given two strings 'STR1' and 'STR2'. You have to check whether the two strings are anagram to each other or not.

// Note:
// Two strings are said to be anagram if they contain the same characters, irrespective of the order of the characters.
// Example :
// If 'STR1' = “listen” and 'STR2' = “silent” then the output will be 1.

// Both the strings contain the same set of characters.

#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    unordered_map<char , int>mp1 ; 
    unordered_map<char,int>mp2 ; 

    int n = str1.length() ; 
    int m = str2.length() ; 

    if(n!=m){
        return false ; 
    }

    for(int i = 0 ; i<n ; i++){
        mp1[str1[i]]++ ; 
        mp2[str2[i]]++ ; 
    }


    for(int i = 0 ; i<n ; i++){
        if(mp1[str1[i]]!=mp2[str1[i]]){

            return false ; 

        }
    }

    return true ; 
}