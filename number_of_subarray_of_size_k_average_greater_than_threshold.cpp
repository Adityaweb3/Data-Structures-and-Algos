// Problem Link : https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/?envType=problem-list-v2&envId=rnow2e3d

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0 ; 
        int j = 0 ; 
        int sum = 0; 
        int count = 0 ; 
        int n = arr.size() ; 

        while(j<n){
            sum+=arr[j] ; 
            if(j-i+1==k && sum/k>=threshold){
                count++ ; 
                sum-=arr[i] ; 
                i++ ; 
                j++ ; 
            }
            else if(j-i+1==k){
                sum-=arr[i] ; 
                i++ ; 
                j++ ; 
            }

            else {
                j++ ; 
            }
        }

        return count ; 
    }