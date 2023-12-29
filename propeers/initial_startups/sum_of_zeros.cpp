/*You are given a binary matrix (it contains only 0s and 1s) with dimensions ‘N * M’. 
You need to find and return the sum of coverages of all zeros of the given matrix.

Coverage for a particular 0 is defined as the total number of ‘1s’ around it 
(i.e., immediate left, immediate right, immediate up, and immediate bottom positions).
*/

#include <bits/stdc++.h> 
int coverageOfMatrix(vector<vector<int>> &mat) {
    // Write your code here.
     int n = mat.size();
    int m = mat[0].size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
              
                if (i - 1 >= 0 && mat[i - 1][j] == 1) {
                    count++;
                }
               
                if (i + 1 < n && mat[i + 1][j] == 1) {
                    count++;
                }
                
                if (j - 1 >= 0 && mat[i][j - 1] == 1) {
                    count++;
                }
               
                if (j + 1 < m && mat[i][j + 1] == 1) {
                    count++;
                }
            }
        }
    }

    return count; 
}
