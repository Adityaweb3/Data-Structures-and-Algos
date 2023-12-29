/*You are given a square matrix, return true if the matrix is symmetric otherwise return false.
*/

#include <bits/stdc++.h> 
bool isMatrixSymmetric(vector<vector<int>> matrix){
    // Write your code here. 
    int n = matrix.size() ; 


    for(int i = 0 ; i<n ; i++){
        for(int j = i ; j <n ; j++){
            if(matrix[i][j]!=matrix[j][i]){
                return false ; 
            }

        }
    }

    return true ; 
}