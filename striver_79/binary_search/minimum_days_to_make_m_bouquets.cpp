// Problem link : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

bool possible(vector<int>arr , int day , int m , int k){
        int n = arr.size() ; 
        int count =0 ; 
        int ans =0 ; 
        for(int i =0 ; i<n ; i++){
            if(arr[i]<=day){
                count++ ; 
            }
            else {
                ans+=(count/k); 
                count=0 ; 
            }
        }
        ans+=(count/k) ; 

        return (ans>=m) ; 
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size() ; 
        int mini = INT_MAX ; 
        int maxi = INT_MIN ; 
        long long val = (long long)m *(long long)k ;

        if(val>n){
            return -1 ; 
        }
        for(int i =0 ; i<n ; i++){
            maxi = max(maxi , bloomDay[i]) ;
            mini = min(mini , bloomDay[i]) ; 
        }

        int low = mini ; 
        int high = maxi ; 

        while(low<=high){
            int mid = low+(high-low)/2 ; 
            if(possible(bloomDay , mid , m , k)){
                high = mid-1 ; 
            }
            else {
                low = mid+1 ;
            }
        }

        return low ; 
    }