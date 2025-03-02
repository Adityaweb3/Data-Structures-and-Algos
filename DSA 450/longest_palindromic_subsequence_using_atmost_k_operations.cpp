// Problem Link : https://leetcode.com/problems/longest-palindromic-subsequence-after-at-most-k-operations/description/

int solve(int i , int j , int k , string &s , vector<vector<vector<int>>>&dp){
    if(i>j){
        return 0; 
    }
    if(i==j){
        return 1 ; 
    }
    if(dp[i][j][k]!=-1){
        return dp[i][j][k] ;
    }
    int ans= solve(i+1 , j , k , s , dp) ; 
    ans = max(ans , solve(i , j-1 , k , s ,dp)) ; 
    int val = min(abs(s[i]-s[j]) , 26-abs(s[i]-s[j])) ; 
    if(k>=val){
        ans = max(ans , 2+solve(i+1 , j-1 , k-val , s , dp)) ; 
    }
    return dp[i][j][k]= ans ; 
}
int longestPalindromicSubsequence(string s, int k) {
    int n = s.size() ; 
    vector<vector<vector<int>>>dp(n , vector<vector<int>>(n , vector<int>(k+1 , -1))) ; 
    return solve(0 , n-1 , k , s , dp) ; 
}