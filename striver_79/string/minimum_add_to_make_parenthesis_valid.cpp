// Problem Link : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

int minAddToMakeValid(string s) {
        int open =0 ; 
        int close =0 ; 
        int n = s.length() ; 
        for(int i =0 ; i<n ; i++){
            if(s[i]=='('){
                open++ ; 
            }
            else {
                if(open==0){
                    close++ ; 
                }
                else {
                    open-- ; 
                }
            }
        }

        return (open+close) ; 
    }