// Problem Link : https://neetcode.io/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() ; 
        int ans = 0 ; 
        int maxi = INT_MIN ; 

        for(int i =0 ; i<n ; i++){
            ans = max(nums[i] , ans+nums[i]) ; 
            maxi = max(maxi , ans) ; 
        }

        return maxi ; 
    }
};
