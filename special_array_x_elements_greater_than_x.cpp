// Problem Link : https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/?envType=daily-question&envId=2024-05-27

class Solution {
public:
    int cnt(vector<int>&nums , int res){
        int ans = 0 ; 
        for(auto num : nums){
            if(num>=res){
                ans++ ; 
            }
        }

        return ans ; 
    }
    int specialArray(vector<int>& nums) {
        int low = 0 ; 
        int high = nums.size() ; 

        while(low<=high){
            int mid = low+(high-low)/2 ; 
            int ans = cnt(nums , mid) ; 

            if(ans ==mid){
                return mid ;
            }
            else if(ans>mid){
                low = mid+1 ; 
            }
            else {
                high = mid-1 ; 
            }
        }

        return -1 ; 


    }
};