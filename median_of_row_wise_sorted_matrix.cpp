// Problem Link : https://www.codingninjas.com/studio/problems/median-of-a-row-wise-sorted-matrix_1115473

int median(vector<vector<int>> &matrix, int m, int n) {
    // Write your code here.
    int mini = matrix[0][0] ; 
    int maxi = matrix[0][n-1] ; 

    for(int i = 1 ; i<m ; i++){
        if(matrix[i][0]<mini){
            mini = matrix[i][0] ; 
        }
        if(matrix[i][n-1]>maxi){
            maxi = matrix[i][n-1] ; 
        }
    }

    int medPos = ((m*n)+1)/2 ; 
    while(mini<maxi){
        int mid = (mini+maxi)/2 ; 
        int midpos = 0 ; 

        for (const auto& row : matrix) {
        midpos += upper_bound(row.begin(), row.end(), mid) - row.begin();
    }

        if(midpos<medPos){
            mini = mid+1 ; 
        }

        else {
            maxi = mid ; 
        }
    }
    return mini ;
}