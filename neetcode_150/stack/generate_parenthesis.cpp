// Problem Link : https://neetcode.io/problems/generate-parentheses

class Solution {
public:
    void helper(vector<string>&res , int n , int oc , int cc , string s){
        if(oc==n && cc ==n){
            res.push_back(s)  ; 
            return ; 
        }

        if(oc<n){
            helper(res , n , oc+1 , cc , s+"(") ;
        }

        if(cc<oc){
            helper(res , n , oc , cc+1 , s+")") ;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        int oc = 0 ; 
        int cc = 0 ; 
        helper(res , n , oc , cc , "") ; 
        return res ; 
    }
};
