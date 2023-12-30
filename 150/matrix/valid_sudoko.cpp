/*Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the f
ollowing rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.*/

#include <bits/stdc++.h> 

bool isValidSudoku(vector<vector<char>>& board) {
        int rowCheck[9][9]= {0} ; 
        int colCheck[9][9]={0} ; 
        int gridCheck[9][9]={0} ; 

        for(int i = 0 ; i<board.size() ; i++){
            for(int j = 0 ; j<board[0].size() ; j++){
                if(board[i][j]!='.'){
                    int number = board[i][j]-'0' ; 

                    int k = (i/3)*3 +(j/3) ;


                    if(rowCheck[i][number-1]++ || colCheck[j][number-1]++ || gridCheck[k][number-1]++){
                        return false ; 
                    }
                }
            }
        }

        return true ;
        
    }