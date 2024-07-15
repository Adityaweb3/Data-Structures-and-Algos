// Problem link : https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
   vector<int>nthRow(int n){
    int res =1 ; 
    vector<int>ans ; 
    ans.push_back(res) ; 
    for(int i =1 ; i<n ; i++){
        res*=(n-i) ; 
        res/=i ; 
        ans.push_back(res) ; 
    }

    return ans ; 
   }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans ; 

        for(int i = 1 ; i<=numRows ; i++){
            ans.push_back(nthRow(i)) ; 
        }

        return ans ;
    }
};