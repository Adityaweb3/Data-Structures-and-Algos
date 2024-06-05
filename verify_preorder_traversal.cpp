// Problem Link : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int x =0 ; 
        int y = 0 ; 

        for(int i =0 ; i<preorder.size() ; i++){
            if(y>x){
                return false ; 
            }

            if(preorder[i]=='#'){
                y++ ; 
            }
            else {
                x++ ; 
            }

            while(i<preorder.size() && preorder[i]!=','){
                i++ ; 
            }
        }

        return x==y-1 ; 
    }
};