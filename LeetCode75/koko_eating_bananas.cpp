// Problem Link : https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:
    long long totalHours(vector<int>&arr , int x){
        long long  total = 0 ; 
        int n = arr.size() ; 
        for(int i = 0 ; i<n; i++){
            total += ceil((double)arr[i] /(double)x) ;
        }
        return total ; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long maxi = INT_MIN ; 
        int n = piles.size() ; 
        int ans = 0 ;

        for(int i = 0 ; i<n ; i++){
            if(piles[i]>maxi){
                maxi = piles[i] ; 
            }
        }

        long long low = 1 ; 
        long long  high = maxi ; 
        while(low<=high){
            long long  mid = low+(high-low)/2 ; 

            long long  total = totalHours(piles , mid) ; 
            if(total<=h){
                ans = mid ;
                high = mid-1 ; 
            }

            else {
                low = mid+1 ; 
            }
        }

        return ans ;
    }
};