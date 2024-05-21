// Problem Link : https://neetcode.io/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowC[9][9]={0} ; 
        int colC[9][9]={0} ; 
        int gridC[9][9]={0} ; 
        int n = board.size() ; 
        int m = board[0].size() ; 

        for(int i = 0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(board[i][j]!='.'){
                    int number = board[i][j]-'0' ; 
                    int k = (i/3)*3 + (j/3) ; 


                    if(rowC[i][number-1]++ || colC[j][number-1]++ || gridC[k][number-1]++){
                        return false ; 
                    }
                }
            }
        }

        return true ; 
    }
};
