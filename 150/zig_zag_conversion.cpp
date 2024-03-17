// Problem Link : https://leetcode.com/problems/zigzag-conversion/description/

 string convert(string s, int numRows) {
        vector<string>ans(numRows) ; 
        if(numRows==1){
            return s; 
        }

        bool flag = false ; 
        int i = 0 ; 

        for(auto c : s){
            ans[i]+=c ; 

            if(i==0 || i== numRows-1){
                flag = !flag ; 
            }

            if(flag){
                i++ ; 
            }
            else {
                i-- ; 
            }
        }
        string zig= "" ; 

        for(auto str : ans){
            zig+=str ; 
        }

        return zig ; 
        
    }