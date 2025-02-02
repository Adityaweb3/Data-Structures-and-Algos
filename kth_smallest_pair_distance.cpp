// Problem Link : https://leetcode.com/problems/find-k-th-smallest-pair-distance/
// Run binary search on answer : the kth min difference will lie between 0  and max diff . 

  bool isvalid(int mid , vector<int>&nums , int k){
        int count = 0 ; 
        int j = 0 ; 
        int n = nums.size() ; 
        for(int i = 0 ; i<n ; i++){
            while(j<n && nums[j]-nums[i]<=mid){
                j++ ; 
            }
            count+=(j-i-1) ; 
        }
        return count>=k ; 
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size() ; 
        sort(nums.begin() , nums.end()) ; 
        int low = 0 ; 
        int high = nums[n-1]-nums[0] ; 
        int ans = -1 ; 
        while(low<=high){
            int mid = low+(high-low)/2 ; 
            if(isvalid(mid , nums , k)){
                ans = mid ; 
                high = mid-1 ; 
            }
            else {
                low = mid+1 ; 
            }
        }

        return ans ; 
    }