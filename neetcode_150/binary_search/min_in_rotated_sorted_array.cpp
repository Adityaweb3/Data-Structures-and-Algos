// Problem Link : https://neetcode.io/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int> &nums) {
        int l =0 ; 
        int r = nums.size()-1 ; 

        while(nums[l]>nums[r]){
            int mid = (l+r)/2 ; 

            if(nums[l]<=nums[mid]){
                l = mid+1 ; 
            }
            else {
                r = mid; 
            }
        }

        return nums[l] ; 
    }
};
