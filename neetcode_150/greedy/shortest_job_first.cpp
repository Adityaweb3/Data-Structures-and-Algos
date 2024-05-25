// Problem Link : https://www.geeksforgeeks.org/problems/shortest-job-first/1

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        long long wt = 0 ; 
        long long t=0 ; 
        int n =bt.size() ; 
        sort(bt.begin() , bt.end()) ; 
        
        for(int i = 0 ; i<n ; i++){
            wt+=t ; 
            t+=bt[i] ; 
        }
        
        return wt/n ; 
    }
};