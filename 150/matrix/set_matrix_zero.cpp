/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.*/
#include <bits/stdc++.h> 
void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size() ; 
        int n = matrix[0].size() ; 

        unordered_map<int , bool>rowMap ; 
        unordered_map<int , bool>colMap ; 


        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j <n ; j++){
                if(matrix[i][j]==0){
                    rowMap[i]=true ;
                    colMap[j] = true ;
                }
            }
        }

        for(auto it : rowMap){
            int temp = it.first ; 
            for(int i = 0 ; i<n ; i++){
                matrix[temp][i] = 0 ; 
            }
        }

        for(auto it : colMap){
            int temp = it.first ; 
            for(int i = 0 ; i<m ; i++){
                matrix[i][temp] = 0 ; 
            }
        }
    }