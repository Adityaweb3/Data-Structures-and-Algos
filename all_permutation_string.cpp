// Problem Link : https://www.codingninjas.com/studio/problems/print-permutations-string_758958

#include <bits/stdc++.h> 
vector<string>ans ; 

void helper(string &s , int i){
    if(i==s.length()){
        ans.push_back(s) ; 
        return ;
    }

    for(int j=i ; j<s.length() ; j++){
        swap(s[i] , s[j]) ; 
        helper(s , i+1) ; 
        swap(s[i] , s[j]) ;
    }
    return ;
}
vector<string> findPermutations(string &s) {
    // Write your code here.

    helper(s , 0) ; 
    return ans;

}