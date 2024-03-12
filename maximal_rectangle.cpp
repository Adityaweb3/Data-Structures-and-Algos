// Problem link : https://leetcode.com/problems/maximal-rectangle/description/

class Solution {
public:
  int largestArea(vector<int>&arr){
    int n = arr.size() ; 
    stack<int>st ; 
    int maxi = 0 ; 
    int i = 0 ; 

    while(i<n){
        if(st.empty() || arr[st.top()]<=arr[i]){
            st.push(i);
            i++ ;
        }

        else {
            int tp  = st.top() ; 
            st.pop() ; 

            int ans = arr[tp]*(st.empty() ? i : i-st.top()-1) ; 
            maxi = max(maxi , ans) ; 
        }
    }

    while(st.empty()==false){
        int tp = st.top() ; 
        st.pop() ; 
        int ans = arr[tp]*(st.empty()?i:i-st.top()-1) ;
        maxi = max(maxi , ans) ;
    }

    return maxi ; 
  }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size() ; 
        int m = matrix[0].size() ; 
        vector<vector<int>> v;

        //convert the matrix to int for our shortcut
        for(int i=0; i<n; i++){
            vector<int> temp;
            for(int j=0; j<m; j++){
                temp.push_back(matrix[i][j] - '0');
            }
            v.push_back(temp);
        }
        int res = largestArea(v[0]) ; 
        for(int i = 1 ; i<n; i++){
            for(int j = 0 ; j<m ; j++){
                if(v[i][j]==1){
                    v[i][j]= 1+v[i-1][j] ; 
                }
            }

            res = max(res , largestArea(v[i])) ; 
        }

        return res ;
    }
};