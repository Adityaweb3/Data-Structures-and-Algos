/*Given an m x n matrix, return all elements of the matrix in spiral order.*/
#include <bits/stdc++.h> 
 vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res ; 
        int r = matrix.size() ; 
        int c = matrix[0].size() ; 

        int rs = 0 , cs = 0 , re = r-1 , ce = c-1 ; 


        while(rs<=re && cs<=ce){
            for(int i = cs ; i<=ce ; i++){
                res.push_back(matrix[rs][i]) ; 


            }

            rs++ ; 


            for(int i = rs ; i<=re ; i++){
                res.push_back(matrix[i][ce]) ; 
            }
            ce-- ; 

            if(rs<=re){
                for(int i = ce ;i>=cs ; i--){
                    res.push_back(matrix[re][i]) ; 
                }

                re-- ; 
            }

            if(cs <=ce){
                for(int i = re ; i>=rs ; i--){
                    res.push_back(matrix[i][cs]) ; 
                }
                cs++ ; 
            }
        }

        return res ; 
        
        
    }