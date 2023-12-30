/*You have been given two strings ‘STR1’ and ‘STR2’.

Your task is to find if ‘STR1’ is a subsequence of ‘STR2’.

A subsequence of a string is a new string that can be derived from the original string by deleting some characters 
(can be none) without changing the relative ordering of other characters.
*/

#include <bits/stdc++.h> 
bool isSubSequence(string str1, string str2) {
    // Write your code here.

   int m = str2.length() ; 
   int n = str1.length() ; 

   int j = 0 ; 

   if(str1==""){
       return true ; 
   }

   for(int i = 0 ; i<m ; i++){
       if(str2[i]==str1[j]){
           j++ ; 
       }

       if(j==n){
           return true ;
       }
   } 

   return false ; 
}