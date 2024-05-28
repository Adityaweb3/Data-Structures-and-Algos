// Problem Link : https://leetcode.com/problems/matrix-diagonal-sum/description/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size() ; 
        int ans =0 ; 
        int mid = n/2 ; 
        for(int i = 0 ; i<n ; i++){
            ans+=mat[i][i]+mat[i][n-i-1] ; 
        }

        if(n%2==1){
            ans-=mat[mid][mid] ;
        }

        return ans ;
    }
};