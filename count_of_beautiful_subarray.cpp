// Problem Link : https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/description/

long long beautifulSubarrays(vector<int>& nums) {
        long long count = 0 ; 
        long long k = 0 ; 
        long long n = nums.size() ; 
        long long r = 0 ; 
        map<long long , long long >mp ; 
        mp[r]++ ; 

        for(long long i = 0 ; i<n ; i++){
            r^=nums[i]  ; 
            int x= r^k ; 

            count+=mp[x] ; 
            mp[r]++ ;
        }

        return count ;
    }