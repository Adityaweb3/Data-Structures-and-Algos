// Problem link : https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/

Approach : 
 
 1. if the current element is negative we will find all the numbers such than nums[i]*nums2[j] should be greater than x.
  Thus we will find the lower bound of x/nums1[i] and increase 
 the count by n2-ind where ind is the index of largest value of nums2 which is lesser than x/nums1[i].

 2. Else if the current element is positive we will find all the numbers such that nums[i]*nums2[j] is lesser than x. 
 thus we will find upper bound of x/nums1[i] and increase the count by ind.

bool isvalid(long long mid , vector<int>&nums1 , vector<int>&nums2 , long long k){
        int n1 = nums1.size() ; 
        int n2= nums2.size() ; 
        long long count = 0 ; 
        for(int i =0 ; i<n1 ; i++){
            if(nums1[i]<0){
                long long rem = ceil((double)mid/nums1[i]) ; 
                int index = lower_bound(nums2.begin() , nums2.end() , rem)-nums2.begin() ; 
                count+=(n2-index) ; 
            }
            else if(nums1[i]>0){
                long long rem = floor((double)mid/nums1[i]) ; 
                int index = upper_bound(nums2.begin() , nums2.end() , rem)-nums2.begin() ; 
                count+=index ;
            }
            else {
                if(mid>=0){
                    count+=n2 ; 
                }
            }
            if(count>=k){
                return true ; 
            }
        }
        return count>=k ; 
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n = nums1.size() ; 
        int m = nums2.size() ; 
        long long low = -1e10 ; 
        long long high =1e10 ;
        long long ans = 0 ; 
        while(low<=high){
            long long mid = low+(high-low)/2 ; 
            if(isvalid(mid , nums1 , nums2 , k)){
                ans = mid ; 
                high = mid-1 ; 
            }
            else{
                low = mid+1 ; 
            }
        }
        return ans ; 
    }