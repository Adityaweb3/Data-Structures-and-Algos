// Problem link : https://leetcode.com/problems/assign-cookies/


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n= s.size() ; 
        if(n==0){
            return 0 ; 
        }
        int maxi = 0 ; 
        sort(g.begin(), g.end()) ;
        sort(s.begin() , s.end()) ; 

        int i =n-1 ; 
        int j= g.size()-1 ; 
        while(i>=0 && j>=0){
            if(s[i]>=g[j]){
                maxi++ ; 
                i-- ; 
                j-- ; 
            }
            else {
                j-- ; 
            }
        }

        return maxi ; 

    }
};