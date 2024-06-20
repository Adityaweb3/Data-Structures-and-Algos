// Problem Link : https://leetcode.com/problems/split-array-largest-sum/description/

class Solution {
public:
    int isFind(vector<int>&nums , int mid){
        int number =1 ; 
        int jobs =0 ; 

        for(int i =0 ; i<nums.size() ; i++){
            if(jobs+nums[i]<=mid){
                jobs+=nums[i] ; 
            }
            else {
                number++ ; 
                jobs= nums[i] ; 
            }
        }

        return number ; 
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size() ; 
        int low = INT_MIN ; int high =0 ; 
        for(int i=0 ; i<n ; i++){
            low = max(low , nums[i]) ; 
            high+=nums[i] ; 
        }

        while(low<=high){
            int mid = low+(high-low)/2 ;  

            int number = isFind(nums , mid) ; 
            if(number>k){
                low = mid+1 ; 
            }
            else {
                high = mid-1 ; 
            }
        }
        return low ; 
    }
};