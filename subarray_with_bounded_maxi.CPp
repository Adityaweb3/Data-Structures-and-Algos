// Problem link : https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& arr, int left, int right) {
        int i = 0 ; 
        int j = 0 ; 
        int count =0 ; 
        int m = 0 ; 

        while(j<arr.size()){
            if(arr[j]>right){
                m=0 ; 
                i = j+1 ; 
            }
            else if(arr[j]>=left && arr[j]<=right){
                m= j-i+1 ; 
            }
            count+=m ; 
            j++ ; 
        }

        return count ; 
    }
};