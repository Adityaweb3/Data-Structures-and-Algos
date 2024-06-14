// Problem Link : https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n= arr.size() ; 
        int low = 0 ; 
        int high = n-1 ; 

        while(low<=high){
            int mid = (low+high)>>1 ;  

            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid ; 
            }

            else if(arr[mid]>arr[mid+1]){
                high = mid ; 
            }
            else {
                low=mid+1 ; 
            }
        }

        return -1 ; 
    }
};