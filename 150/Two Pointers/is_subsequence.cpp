/*Given two strings s and t, return true if s is a subsequence of t, or false otherwise.*/


#include <bits/stdc++.h> 
bool isSubsequence(string s, string t) {

        int j = 0 ; 
        if(s=="") return true ; 

        for(int i = 0 ; i<t.size() ; i++){
            if(s[j]==t[i]){
                j++ ;
            }

            if(j==s.size()){
                return true ; 
            }
        }

        return false ; 
        
    }