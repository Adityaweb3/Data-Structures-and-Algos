// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.

#include <bits/stdc++.h> 
vector<vector<string> > groupAnagramsTogether(vector<string> &strList)
{
    // Write your code here. 
    vector<vector<string>>ans ; 
    unordered_map<string , vector<string>>mp ;


    for(auto str : strList){
        string s = str ; 
        sort(s.begin() , s.end()) ; 
        mp[s].push_back(str) ; 
    } 

    for(auto i : mp){
        ans.push_back(i.second) ;
    } 

    return ans ;
}