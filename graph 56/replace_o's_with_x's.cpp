// Problem Link : https://leetcode.com/problems/surrounded-regions/description/

class Solution {
public:

     int dx[4] = {-1 , 1 , 0 , 0}; 
    int dy[4] = {0 , 0 , -1 , 1} ; 
    
    bool isValid(int i , int j, int &n , int &m ){
        return (i>=0 && j>=0 && i<n && j<m) ;
    }
    
    bool isBoundary(int i , int j , int &n , int &m){
        return (i==0 || j==0 || i ==n-1 || j==m-1) ;
    }
    
    void setNotClosed(int i , int j  , int &n , int &m , vector<vector<char>>&mat){
        mat[i][j] = 'N' ; 
        for(int d = 0 ; d<4 ;d++){
            int ii = dx[d]+i ; 
            int jj = dy[d]+ j ; 
            
            if(isValid(ii , jj , n , m) && mat[ii][jj]=='O'){
                setNotClosed(ii , jj , n, m , mat) ;
            }
        }
    }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size() ; 
        int m = mat[0].size() ;
         for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(isBoundary(i,j,n,m) && mat[i][j]== 'O'){
                    setNotClosed(i,j,n,m,mat) ;
                }
            }
        }
        
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(mat[i][j]=='O'){
                    mat[i][j] = 'X' ; 
                    
                }
                
                else if(mat[i][j]=='N'){
                    mat[i][j]='O' ;
                }
            }
        }
    }
};