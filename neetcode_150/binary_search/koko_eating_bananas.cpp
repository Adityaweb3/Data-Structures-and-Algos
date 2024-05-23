// Problem Link : https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:
   int total (vector<int>& piles , int x){
    long long sum = 0; 
    for(int i = 0 ; i<piles.size() ; i++){
        sum+= ceil((double)piles[i] /(double)x) ; 
    }
    return sum ; 
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size() ; 
        int ans = 0 ; 
        long long maxi = INT_MIN ; 
        for(int i=0 ; i<n ; i++){
            if(piles[i]>maxi){
                maxi = piles[i] ; 
            }
        }

        long long low = 1; 
        long long high =maxi ; 

        while(low<=high){
            long long  mid = low+(high-low)/2 ; 
            long long t = total(piles , mid) ;

            if(t<=h){
                ans = mid ; 
                high= mid-1 ; 
            }
            else {
                low= mid+1 ; 
            }
        }

        return ans ; 
    }
};
