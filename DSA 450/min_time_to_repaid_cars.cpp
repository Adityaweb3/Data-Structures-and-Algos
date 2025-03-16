// Problem link : https://leetcode.com/problems/minimum-time-to-repair-cars/

bool isvalid(long long mid , vector<int>&nums , int k){
    int count = 0 ; 
    for(auto i : nums){
        count+=sqrt(mid/i); 
        if(count>=k){
            return true ; 
        }
    }
    return count>=k ; 
}
long long repairCars(vector<int>& ranks, int cars) {
    long long low = 1 ; 
    long long high = 1e14 ; 
    long long ans = 0 ; 
    while(low<=high){
        long long mid = low+(high-low)/2 ; 
        if(isvalid(mid , ranks , cars)){
            ans = mid ; 
            high = mid-1 ; 
        }
        else {
            low = mid+1 ; 
        }
    }
    return ans; 
}