// Problem Link : https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1

int LCSof3 (string str1, string str2, string str3, int n1, int n2, int n3)
        {
            // your code here
            int t[n1+1][n2+1][n3+1];
            for(int i = 0 ; i < n1+1 ; i++){
                for(int j = 0 ; j < n2+1 ; j++){
                    for(int k = 0 ; k < n3+1 ; k++){
                        if(i == 0 || j == 0 || k == 0){
                            t[i][j][k] = 0;
                        }
                    }
                }
            }
            for(int i = 1 ; i < n1+1 ; i++){
                for(int j = 1 ; j < n2+1 ; j++){
                    for(int k = 1 ; k < n3+1 ; k++){
                        if(str1[i-1] == str2[j-1] and str2[j-1] == str3[k-1]){
                            t[i][j][k] = 1 + t[i-1][j-1][k-1];
                        }
                        else{
                            t[i][j][k] = max(t[i-1][j][k] , max(t[i][j-1][k] , t[i][j][k-1]));
                        }
                    }
                }
            }
            return t[n1][n2][n3];
        }