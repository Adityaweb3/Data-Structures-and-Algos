// Problem Link : https://leetcode.com/problems/single-element-in-a-sorted-array/

//for the right half : 1st instance is at odd index and 2nd instance is at even index 
//for the left half : 1st instance is at even index and 2nd instance is at odd index 

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low =0 ; 
        int high = nums.size()-2 ; 
        while(low<=high){
            int mid = (low+high)>>1;
            if(nums[mid]==nums[mid^1]){
                low = mid+1 ; 
            }
            else {
                high =mid-1 ;
            }
        }

        return nums[low] ; 
    }
};