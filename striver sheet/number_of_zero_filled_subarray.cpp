// Problem link : https://leetcode.com/problems/number-of-zero-filled-subarrays/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0 ;
        int n= nums.size() ; 
        for(int i =0 ; i<nums.size() ; i++){
            long long count = 0 ; 
            while(i<n && nums[i]==0){
                i++ ;
                count++ ; 
            }
            ans+=(count)*(count+1)/2 ; 
        }
        return ans ; 
    }
};