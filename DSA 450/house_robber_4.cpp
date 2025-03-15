// Problem Link : https://leetcode.com/problems/house-robber-iv/

bool isvalid(int mid , vector<int>&nums , int k){
    int count=0 ; 
    int n = nums.size() ; 
    for(int i = 0 ; i<n ; i++){
        if(nums[i]<=mid){
            count++ ; 
            i++ ; 
        }
    }
    return count>=k ; 
}
int minCapability(vector<int>& nums, int k) {
    int n = nums.size() ; 
    int low = 1; 
    int high = INT_MIN ; 
    int ans =-1 ; 
    for(int i = 0 ; i<n ; i++){
        high = max(high , nums[i]) ; 
    }
    while(low<=high){
        int mid = low+(high-low)/2 ; 
        if(isvalid(mid , nums , k)){
            ans= mid ; 
            high = mid-1 ; 
        }
        else {
            low = mid+1 ; 
        }
    }
    return ans ; 
}